//
// Created by rperrot on 3/25/25.
//

#include "AtributesParser.hpp"

AtributesParser::AtributesParser()
{
}

AtributesParser::AtributesParser(const std::string &key, const std::string &value, const std::vector<AtributesParser> &values)
		: key(key), value(value), children(values)
{

}

const std::string &AtributesParser::getValue() const
{
	return value;
}

void AtributesParser::setValue(const std::string &value)
{
	AtributesParser::value = value;
}

const std::vector<AtributesParser> &AtributesParser::getChildren() const
{
	return children;
}

void AtributesParser::setChildren(const std::vector<AtributesParser> &values)
{
	AtributesParser::children = values;
}

const std::string &AtributesParser::getKey() const
{
	return key;
}

void AtributesParser::setKey(const std::string &key)
{
	AtributesParser::key = key;
}

void AtributesParser::addChildren(const AtributesParser &value)
{
	this->children.push_back(value);
}
