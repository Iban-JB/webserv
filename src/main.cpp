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
#include "Configuration.hpp"

int	main(int argc, char const *argv[])
{
	std::string configPath;
	if (argc == 1)
		configPath = "./config/default.conf";
	else
		configPath = argv[1];
	Configuration config(configPath);
	return (0);
}
