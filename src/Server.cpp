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

int Server::get_port() const
{
	return _port;
}

const std::string &Server::get_host() const
{
	return _host;
}

const std::string &Server::get_name() const
{
	return _name;
}

const std::vector<Location> &Server::get_loc() const
{
	return _loc;
}


Server::Server(const std::string &name, int port, const std::string &host, const std::vector<Location> &loc): _port(port), _host(host),  _name(name),
 _loc(loc)
{}

