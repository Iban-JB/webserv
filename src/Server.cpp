/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-20 11:54:20 by ibjean-b          #+#    #+#             */
/*   Updated: 2025-03-20 11:54:20 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "defines.hpp"
#include <sys/epoll.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <cerrno>
#include <netdb.h>
#include <sys/types.h>
#include <fcntl.h>

#include <sys/wait.h> //REMOVE THIS LINE LATER
Server::Server()
{
}

Server::~Server()
{
}

Server::Server(int port, std::string name, std::string host, std::vector<Location> *locations, bool is_on)
{
	_port = port;
	_name = name;
	_host = host;
	_loc = locations;
	_on = is_on;
}

void	Server::start(void)
{
	int	fd_sock = socket(AF_INET, SOCK_STREAM, 0);

	int opt = 1;
	setsockopt(fd_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int)); //REMOVE THIS LINE LATER

	if (fd_sock == -1)
		throw (std::runtime_error("Error: creating socket failed: " + std::string(strerror(errno))));

	if (fcntl(fd_sock, F_SETFL, O_NONBLOCK) == -1)
		throw (std::runtime_error("Error: fcntl on socket failed: " + std::string(strerror(errno))));

	sockaddr_in		network;
	network.sin_family = AF_INET;
	network.sin_port = htons(_port);
	network.sin_addr.s_addr = INADDR_ANY; //change depending on host //! IMPORTANT ! 

	if (bind(fd_sock, (struct sockaddr*)&network, sizeof(network)) == -1)
		throw (std::runtime_error("Error: binding socket failed: " + std::string(strerror(errno))));
	
	if (listen(fd_sock, SOMAXCONN))
		throw (std::runtime_error("Error: listening on socket failed: " + std::string(strerror(errno))));
	
	try
	{
		this->run(fd_sock);
	}
	catch(const std::exception& e)
	{
		throw;
	}
}

void	Server::run(int fd_sock)
{
	int							fd_epoll = epoll_create1(0);
	epoll_event					ev, events[MAX_FD];

	if (fd_epoll == -1)
		throw (std::runtime_error("Error: creating epoll failed: " + std::string(strerror(errno))));

	ev.data.fd = fd_sock;
	ev.events = EPOLLIN | EPOLLOUT | EPOLLRDHUP;
	if (epoll_ctl(fd_epoll, EPOLL_CTL_ADD, fd_sock, &ev) == -1)
		throw (std::runtime_error("Error: adding socket to epoll failed: " + std::string(strerror(errno))));

	int nb_fd;
	while (_on)
	{
		nb_fd = epoll_wait(fd_epoll, events, MAX_EVENTS, -1);
		if (nb_fd == -1)
			throw (std::runtime_error("Error: waiting for epoll failed: " + std::string(strerror(errno))));
		try
		{
			for (int i = 0; i < nb_fd; i++)
			{
				if (events[i].data.fd == fd_sock)
					accept_client(fd_sock, fd_epoll);
				else if (events[i].events & EPOLLRDHUP)
					disconnect_client(fd_epoll, events->data.fd);
				else if (events[i].events & EPOLLIN)
					client_request(fd_epoll, events[i].data.fd);
			}
		}
		catch(const std::exception& e)
		{
			throw ;
		}
	}	
}

void	Server::disconnect_client(int fd_epoll, int fd_client)
{
	if (epoll_ctl(fd_epoll, EPOLL_CTL_DEL, fd_client, NULL) == -1)
		throw (std::runtime_error("Error: deleting client from epoll failed: " + std::string(strerror(errno))));
	if (close(fd_client) == -1)
		throw (std::runtime_error("Error: closing client socket failed: " + std::string(strerror(errno))));
	std::cout << "Client disconnected" << std::endl;
}

void	Server::accept_client(int fd_sock, int fd_epoll)
{
	epoll_event		ev;
	sockaddr_in		client;
	socklen_t		client_size = sizeof(client);
	int				fd_client = accept(fd_sock, (struct sockaddr*)&client, &client_size);

	ev.data.fd = fd_client;
	ev.events = EPOLLRDHUP | EPOLLIN | EPOLLOUT;
	if (fd_client == -1)
		throw (std::runtime_error("Error: accepting client failed: " + std::string(strerror(errno))));
		
	if (fcntl(fd_client, F_SETFL, O_NONBLOCK) == -1)
		throw (std::runtime_error("Error: fcntl on client failed: " + std::string(strerror(errno))));

	if (epoll_ctl(fd_epoll, EPOLL_CTL_ADD, fd_client, &ev) == -1)
		throw (std::runtime_error("Error: adding client to epoll failed: " + std::string(strerror(errno))));
	else // remove this later
		std::cout << "Client connected" << std::endl;
}

void	Server::client_request(int fd_epoll, int fd_client)
{
	char	buffer[1024];
	int		ret = recv(fd_client, buffer, 1024, 0);

	if (ret == -1)
		throw (std::runtime_error("Error: receiving data from client failed: " + std::string(strerror(errno))));
	else if (ret == 0)
		disconnect_client(fd_epoll, fd_client);
	else
		std::cout << "Client sent: " << buffer << std::endl;
}

void	Server::setPort(int port)
{
	this->_port = port;
}

void	Server::setOn(bool is_on)
{
	this->_on = is_on;
}

void	Server::setName(std::string name)
{
	this->_name = name;
}

void	Server::setHost(std::string host)
{
	this->_name = host;
}

void	Server::setLoc(std::vector<Location> *location)
{
	this->_loc = location;
}

std::string	Server::getName(void)
{
	return (this->_name);
}

std::string	Server::getHost(void)
{
	return (this->_host);
}

int	Server::getPort(void)
{
	return (this->_port);
}

bool	Server::getOn(void)
{
	return (this->_on);
}

std::vector<Location>	*Server::getLoc(void)
{
	return (this->_loc);
}

std::ostream &	operator<<(std::ostream &o, Server &serv)
{
	o << "SERVER :" << std::endl;
	o << "	- NAME : " << serv.getName() << std::endl;
	o << "	- HOST : " << serv.getHost() << std::endl;
	o << "	- PORT : " << serv.getPort() << std::endl;
	o << "	- LOCATIONS : NULL"  << std::endl;//<< serv.getLoc();
	return (o);
}