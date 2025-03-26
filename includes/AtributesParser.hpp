//
// Created by rperrot on 3/25/25.
//

#ifndef WEBSERV_ATRIBUTESPARSER_HPP
#define WEBSERV_ATRIBUTESPARSER_HPP
# include <iostream>
# include <vector>

class AtributesParser
{
public:
	AtributesParser(const std::string &key, const std::string &value, const std::vector<AtributesParser> &values);
	AtributesParser();
	const std::string &getValue() const;
	void setValue(const std::string &value);
	const std::vector<AtributesParser> &getChildren() const;
	void setChildren(const std::vector<AtributesParser> &values);
	const std::string &getKey() const;
	void setKey(const std::string &key);
	void addChildren(const AtributesParser &value);

private:
	std::string key;
	std::string value;
	std::vector<AtributesParser> children;
};


#endif
