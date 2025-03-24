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
		throw (std::runtime_error("Error: creating socket failed"));
	
	sockaddr_in		network;
	network.sin_family = AF_INET;
	network.sin_port = htons(_port);
	network.sin_addr.s_addr = INADDR_ANY; //change depending on host //! IMPORTANT ! 

	if (bind(fd_sock, (struct sockaddr*)&network, sizeof(network)) == -1)
		throw (std::runtime_error("Error: binding socket failed: " + std::string(strerror(errno))));
	
	if (listen(fd_sock, MAX_LISTEN))
		throw (std::runtime_error("Error: listening on socket failed: " + std::string(strerror(errno))));
	
	try
	{
		this->run(fd_sock);
	}
	catch(const std::exception& e)
	{
		throw (e);
	}
}

void	Server::run(int fd_sock)
{
	int							fd_epoll = epoll_create1(0);
	epoll_event					events, trigger_events;;

	if (fd_epoll == -1)
		throw (std::runtime_error("Error: creating epoll failed: " + std::string(strerror(errno))));

	events.data.fd = fd_sock;
	if (epoll_ctl(fd_epoll, EPOLL_CTL_ADD, fd_sock, &events) == -1)
		throw (std::runtime_error("Error: adding socket to epoll failed: " + std::string(strerror(errno))));

	events.events = EPOLLIN | EPOLLOUT | EPOLLRDHUP;
	while (_on)
	{
		if (epoll_wait(fd_epoll, &trigger_events, 1, -1) == -1)
			throw (std::runtime_error("Error: waiting for epoll failed: " + std::string(strerror(errno))));

		try
		{
			if (trigger_events.data.fd == fd_sock && trigger_events.events & EPOLLIN)
			{
				accept_client(fd_sock, fd_epoll, &events);
				std::cout << "Client connected !" << std::endl;
			}
			else// if (trigger_events.events & EPOLLIN)
			{
				std::cout << "Client SENDING DAATA !" << std::endl;
				client_request(fd_sock);
				std::cout << "Client sent data !" << std::endl;
				//not working yet ::sadface:: ::reallysadface::
			}
		}
		catch(const std::exception& e)
		{
			throw (e);
		}
		// sleep(2);
	}	
}

void	Server::accept_client(int fd_sock, int fd_epoll, epoll_event *events)
{
	sockaddr_in		client;
	socklen_t		client_size = sizeof(client);
	int				fd_client = accept(fd_sock, (struct sockaddr*)&client, &client_size);

	if (fd_client == -1)
		throw (std::runtime_error("Error: accepting client failed: " + std::string(strerror(errno))));
	if (epoll_ctl(fd_epoll, EPOLL_CTL_ADD, fd_client, events) == -1)
		throw (std::runtime_error("Error: adding client to epoll failed: " + std::string(strerror(errno))));
}

void	Server::client_request(int fd_sock)
{
	char	buffer[1024];
	int		ret = recv(fd_sock, buffer, 1024, 0);

	if (ret == -1)
		throw (std::runtime_error("Error: receiving data from client failed: " + std::string(strerror(errno))));
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