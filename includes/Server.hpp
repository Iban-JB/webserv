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
#include "AAttributes.hpp"

class Server : public AAttributes
{
private:
	int						_port;
	bool					_on;
	std::string				_host;
	std::string				_name;
	std::vector<Location>	*_loc;
public:
	//CONSTRUCTOR AND DESTRUCTOR
	Server();
	~Server();
	Server(int port, std::string name, std::string host, std::vector<Location> *locations, bool is_on);

	void	start(void);

	//GETTERS AND SETTERS
	int						getPort(void);
	bool					getOn(void);
	std::string				getHost(void);
	std::string				getName(void);
	std::vector<Location>	*getLoc(void);

	void	setOn(bool is_on);
	void	setPort(int port);
	void	setName(std::string name);
	void	setHost(std::string host);
	void	setLoc(std::vector<Location> *location);
};

std::ostream &	operator<<(std::ostream &o, Server &serv);

#endif