/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-19 16:59:30 by ibjean-b          #+#    #+#             */
/*   Updated: 2025-03-19 16:59:30 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include <fstream>

Parser::Parser()
{
}

Parser::~Parser()
{
}

Parser::Parser(std::string config_file)
{
	std::ifstream file;
	try
	{
		file.open(config_file.c_str());
		if (!file.is_open())
			throw (std::runtime_error("Error: could not open file"));
		//parse_file(file);
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}