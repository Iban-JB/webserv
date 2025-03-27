//
// Created by rperrot on 3/27/25.
//

#ifndef WEBSERV_EXTENDSSTRING_HPP
#define WEBSERV_EXTENDSSTRING_HPP

#define WAITSPACE " \a\b\f\n\r\t\v"

#include <iostream>

class ExtendsString : public std::string
{
public:
	ExtendsString();
	ExtendsString(std::string &str);
	std::string getAfterSpace();
};


#endif //WEBSERV_EXTENDSSTRING_HPP
