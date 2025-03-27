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

	const std::string &getName() const;
	void setName(const std::string &name);
	int getPort() const;
	void setPort(int port);
	const std::string &getHost() const;
	void setHost(const std::string &host);
	const std::vector<Location> &getLoc() const;
	void setLoc(const std::vector<Location> &loc);
	bool isOn() const;
	void setOn(bool on);

private:
	int						_port;
	std::string				_host;
	std::string				_name;
	std::vector<Location>	_loc;
	bool 					_on;
};

#endif