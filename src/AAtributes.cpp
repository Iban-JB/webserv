/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAttributes.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-21 14:01:10 by ibjean-b          #+#    #+#             */
/*   Updated: 2025-03-21 14:01:10 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "AAtributes.hpp"


AAtributes::AAtributes():_autoIndex(false)
{
}

AAtributes::~AAtributes()
{

}

AAtributes::AAtributes(const std::string &root, const std::map<int, std::string> &error_pages, const std::vector<EHttpMethode> &http_methode, const bool auto_index, const std::vector<std::string> &index)
		: _root(root), _errorPages(error_pages), _httpMethode(http_methode), _autoIndex(auto_index), index(index)
{}

const std::string &AAtributes::get_root() const
{
	return _root;
}

const std::map<int, std::string> &AAtributes::get_error_pages() const
{
	return _errorPages;
}

const std::vector<EHttpMethode> &AAtributes::get_http_methode() const
{
	return _httpMethode;
}

const bool AAtributes::get_auto_index() const
{
	return _autoIndex;
}

const std::vector<std::string> &AAtributes::get_index() const
{
	return index;
}

