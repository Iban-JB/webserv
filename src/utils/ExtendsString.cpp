#include "ExtendsString.hpp"

std::string ExtendsString::getAfterSpace(){
	std::size_t i = -1;
	while (++i < this->length() && (((*this)[i] == ' ') || ((*this)[i] >= 7 && (*this)[i] <= 13)))
		;
	std::string response = this->substr(i);
	std::cout << response << std::endl;
	size_t commentIndex = response.find('#');
	if (commentIndex != std::string::npos)
		response = response.substr(0, commentIndex);
	while (response.length() && (response[response.length() - 1] == ' ' || (response[response.length() - 1] >= 7 && response[response.length() - 1] <= 13)))
		response = response.substr(0, response.length() - 1);
	std::cout << response << std::endl;
	return response;
}

ExtendsString::ExtendsString(std::string &str):std::string(str){
}