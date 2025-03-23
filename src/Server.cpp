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

#include <sys/wait.h>
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
	if (fd_sock == -1)
		throw (std::runtime_error("Error: creating socket failed"));
	
	sockaddr_in		network;
	network.sin_family = AF_INET;
	network.sin_port = htons(_port);
	network.sin_addr.s_addr = INADDR_ANY;

	if (bind(fd_sock, (struct sockaddr*)&network, sizeof(network)) == -1)
		throw (std::runtime_error("Error: binding socket failed"));
	
	if (listen(fd_sock, MAX_LISTEN))
		throw (std::runtime_error("Error: binding socket failed"));
	
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
	int	fd_poll = epoll_create1(0);
	if (fd_poll == -1)
		throw (std::runtime_error("Error: creating epoll failed: " + std::string(strerror(errno))));

	epoll_event	event;
	event.events = EPOLLIN;
	event.data.fd = fd_sock;

	while (_on)
	{
		std::cout << "Waiting for connection" << std::endl;
		sleep(10);
	}	
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