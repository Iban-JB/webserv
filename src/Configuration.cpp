//
// Created by rperrot on 3/25/25.
//

#include "Configuration.hpp"
#include "Parser.hpp"

Configuration::Configuration(std::string fileName)
{
	Parser parser(fileName);
}

Configuration::~Configuration()
{
}