/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAtributes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-21 14:00:01 by ibjean-b          #+#    #+#             */
/*   Updated: 2025-03-21 14:00:01 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AATTRIBUTES
# define AATTRIBUTES

# include <iostream>
# include <vector>
# include "Http.hpp"
# include <map>

class AAtributes
{
protected:
	const std::string					_root;
	const std::map<int, std::string> 	 _errorPages;
	const std::vector<EHttpMethode> 	_httpMethode;
	const bool							_autoIndex;
	const std::vector <std::string>		index;

public:
	AAtributes();
	AAtributes(const std::string &root, const std::map<int, std::string> &error_pages, const std::vector<EHttpMethode> &http_methode, const bool auto_index, const std::vector<std::string> &index);
	virtual ~AAtributes();
	const std::string &get_root() const;
	const std::map<int, std::string> &get_error_pages() const;
	const std::vector<EHttpMethode> &get_http_methode() const;
	const bool get_auto_index() const;
	const std::vector<std::string> &get_index() const;
};

#endif