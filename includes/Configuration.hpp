
#ifndef WEBSERV_CONFIGURATION_H
#define WEBSERV_CONFIGURATION_H

#include "Server.hpp"
#include <vector>

class Configuration
{
public:
	Configuration(std::string fileName);
	~Configuration();
private:
	std::vector<Server> _serveurs;
};

#endif
