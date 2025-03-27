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

Server::Server()
{
}

Server::~Server()
{
}

Server::Server(const std::string &name, int port, const std::string &host, const std::vector<Location> &loc): _port(port), _host(host),  _name(name),
 _loc(loc)
{}

const std::string &Server::getName() const
{
	return _name;
}

void Server::setName(const std::string &name)
{
	_name = name;
}

int Server::getPort() const
{
	return _port;
}

void Server::setPort(int port)
{
	_port = port;
}

const std::string &Server::getHost() const
{
	return _host;
}

void Server::setHost(const std::string &host)
{
	_host = host;
}

const std::vector<Location> &Server::getLoc() const
{
	return _loc;
}

void Server::setLoc(const std::vector<Location> &loc)
{
	_loc = loc;
}

bool Server::isOn() const
{
	return _on;
}

void Server::setOn(bool on)
{
	_on = on;
}

