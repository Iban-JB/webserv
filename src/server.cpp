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
			throw (std::runtime_error("Error: missing semicolon"));
		}

		std::string attribute = is_attribute(line);
		if (!(attribute.empty()))
		{
			if (is_in_config(attribute))
				throw (std::runtime_error("Error: duplicate attribute"));
			if (attribute == "listen")
				this->_config.insert(std::pair<attributes, std::string>(LISTEN, line));
			if (attribute == "server_name")
				this->_config.insert(std::pair<attributes, std::string>(NAME, line));
			if (attribute == "cgi")
				this->_config.insert(std::pair<attributes, std::string>(CGI, line));
			if (attribute == "client_max_body_size")
				this->_config.insert(std::pair<attributes, std::string>(BODY_SIZE, line));
			if (attribute == "limit_except")	
				this->_config.insert(std::pair<attributes, std::string>(LIMIT_EXCEPT, line));
			if (attribute == "location")
			{
				std::string location = "";
				while (std::getline(file, line) && line.find("}") == std::string::npos)
				{
					display_config();
					attribute = is_attribute(line);
					if (!(attribute.empty()) && is_in_config(attribute))
					{
						std::cerr << "test\n" << line << std::endl;
						std::cerr << attribute << std::endl;
						throw (std::runtime_error("Error: duplicate attribute"));
					}
					else if (attribute.empty())
						location += line;
				}
				this->_config.insert(std::pair<attributes, std::string>(LOCATION, location));
			}
		}

	}
	if (_config.empty())
		throw std::runtime_error("Error: could not find any server block");
}

void	server::display_config(void)
{
	std::map<attributes, std::string>::iterator it = this->_config.begin();
	while (it != this->_config.end())
	{
		std::cout << it->first << " : " << it->second << std::endl;
		it++;
	}
}

std::string	server::is_attribute(std::string &line)
{
	if (line.find("listen") != std::string::npos)
		return ("listen");
	if (line.find("server_name") != std::string::npos)
		return ("server_name");
	if (line.find("cgi") != std::string::npos)
		return ("cgi");
	if (line.find("client_max_body_size") != std::string::npos)
		return ("client_max_body_size");
	if (line.find("location") != std::string::npos)
		return ("location");
	if (line.find("limit_except") != std::string::npos)
		return ("limit_except");
	return ("");
}

bool	server::is_in_config(std::string &attribute)
{
	std::map<attributes, std::string>::iterator it = this->_config.begin();
	while (it != this->_config.end())
	{
		if (it->second.find(attribute) != std::string::npos)
			return (true);
		it++;
	}
	return (false);
}