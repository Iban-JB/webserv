/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-17 11:32:07 by ibjean-b          #+#    #+#             */
/*   Updated: 2025-03-17 11:32:07 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SERVER_HPP
#define	SERVER_HPP

#include <iostream>
#include <map>


class server
{
	enum elements
	{
		NAME,
		LISTEN,
		CGI,
		BODY_SIZE,
		LOCATION,
		LIMIT_EXCEPT,
	};

	private:
		bool							_running;
		std::map<elements, std::string>	_config;

	public:
		server();
		~server();
		server(const std::string config_file);
		void	parse_file(std::ifstream &file);
};

#endif