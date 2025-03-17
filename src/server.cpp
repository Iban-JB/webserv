/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-17 11:33:00 by ibjean-b          #+#    #+#             */
/*   Updated: 2025-03-17 11:33:00 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <fstream>
#include <cstring>

server::~server()
{
}

server::server()
{
}

server::server(const std::string config_file) : _running(true)
{
	std::ifstream file;
	try
	{
		file.open(config_file.c_str());
		if (!file.is_open())
			throw std::runtime_error("Error: could not open file");
		parse_file(file);
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	_running = false;
}

void	server::parse_file(std::ifstream &file)
{
	std::string line;
	do
	{
		if (line.empty())
			continue;
		if (line.find("server") != std::string::npos && line.find("server_name") == std::string::npos)
			break;
	}
	while (std::getline(file, line));
	if (file.eof())
		throw std::runtime_error("Error: could not find server block");

	while (std::getline(file, line) && line.find("}") == std::string::npos)
	{
		if (line.find(";") == std::string::npos && !(line.find("{") == std::string::npos || line.find("}") == std::string::npos))
		{
			std::cerr << line << std::endl;
			throw std::runtime_error("Error: missing semicolon");
		}
		if (line.find("listen") != std::string::npos)
			this->_config.insert(std::pair<elements, std::string>(LISTEN, line));
		if (line.find("server_name") != std::string::npos)
			this->_config.insert(std::pair<elements, std::string>(NAME, line));
		if (line.find("cgi") != std::string::npos)
			this->_config.insert(std::pair<elements, std::string>(CGI, line));
		if (line.find("client_max_body_size") != std::string::npos)
			this->_config.insert(std::pair<elements, std::string>(BODY_SIZE, line));
		if (line.find("limit_except") != std::string::npos)
			this->_config.insert(std::pair<elements, std::string>(LIMIT_EXCEPT, line));
		if (line.find("location") != std::string::npos && line.find("{") != std::string::npos)
		{
			std::string location = "";
			while (std::getline(file, line) && line.find("}") == std::string::npos)
				location += line;
			this->_config.insert(std::pair<elements, std::string>(LOCATION, location));
		}
	}
	if (_config.empty())
		throw std::runtime_error("Error: could not find any server block");

	std::map<elements, std::string>::iterator it = this->_config.begin();
	while (it != this->_config.end())
	{
		std::cout << it->first << " : " << it->second << std::endl;
		it++;
	}
}