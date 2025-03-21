/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-17 11:28:19 by ibjean-b          #+#    #+#             */
/*   Updated: 2025-03-17 11:28:19 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Server.hpp"

int	main(int argc, char const *argv[])
{
	std::string	config = "config/default.conf";
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " [config_file]" << std::endl;
		return (1);
	}
	else
		config = argv[1];
	try
	{
		std::vector<Location>	loc;
		Server	test_sevr(8080, "myServ", "localhost", &loc, true);
		std::cout << test_sevr;
		test_sevr.start();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
