/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-19 16:57:55 by ibjean-b          #+#    #+#             */
/*   Updated: 2025-03-19 16:57:55 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>
#include "AtributesParser.hpp"

class Parser
{
private:
	std::string _config_file;
	std::vector<AtributesParser> _config;
public:
	Parser();
	~Parser();
	Parser(std::string config_file);
};

#endif