/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AATributes.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-21 14:00:01 by ibjean-b          #+#    #+#             */
/*   Updated: 2025-03-21 14:00:01 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AATTRIBUTES
# define	AATTRIBUTES

# include <iostream>
# include <vector>
# include "Http.hpp"

class AATributes
{
private:
	std::string					_root;
	std::map<int, std::string>  _errorPages;
	std::vector<EHttpMethode> 	_httpMethode;
	bool						_autoIndex;
	vector<std::string>			_index;

public:
	AATributes();
	virtual ~AATributes();
};

#endif