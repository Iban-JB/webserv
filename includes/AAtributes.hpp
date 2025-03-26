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
	std::string					_root;
	std::map<int, std::string> 	_errorPages;
	std::vector<EHttpMethode> 	_httpMethode;
	bool						_autoIndex;
	std::vector <std::string>	_index;
public:
public:

	AAtributes();
	AAtributes(const std::string &root, const std::map<int, std::string> &error_pages, const std::vector<EHttpMethode> &http_methode,  bool auto_index, const std::vector<std::string> &index);
	virtual ~AAtributes();
	const std::string &getRoot() const;
	const std::map<int, std::string> &getErrorPages() const;
	const std::vector<EHttpMethode> &getHttpMethode() const;
	const std::vector<std::string> &getIndex() const;
	bool isAutoIndex() const;
	void setRoot(const std::string &root);
	void setHttpMethode(const std::vector<EHttpMethode> &httpMethode);
	void setErrorPages(const std::map<int, std::string> &errorPages);
	void setIndex(const std::vector<std::string> &index);
	void setAutoIndex(bool autoIndex);

};

#endif