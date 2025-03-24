/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-20 11:55:11 by ibjean-b          #+#    #+#             */
/*   Updated: 2025-03-20 11:55:11 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERVER_HPP
#define	SERVER_HPP

#include <map>
#include <vector>
#include <iostream>
#include "Location.hpp"
#include "AAtributes.hpp"

class Server : public AAtributes
{
public:

	Server();
	Server(const std::string &name, int port, const std::string &host, const std::vector<Location> &loc);
	~Server();

	int get_port() const;
	const std::vector<Location> &get_loc() const;
	const std::string 			&get_host() const;
	const std::string 			&get_name() const;

	explicit Server(const std::string &host);

private:
	int						_port;
	std::string				_host;
	std::string				_name;
	std::vector<Location>	_loc;
};

#endif