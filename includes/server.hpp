/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
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
#include "location.hpp"
#include "AAttributes.hpp"

class server : public AAttributes
{
private:
	int						_port;
	std::string				_host;
	std::string				_name;
	std::vector<location>	_loc;
public:
	server();
	~server();		
};

#endif