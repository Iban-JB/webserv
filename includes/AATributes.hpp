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
#define	AATTRIBUTES

#include <iostream>
#include <vector>

class AATributes
{
private:
	std::string					_root;
	std::vector<std::string>	_error_pages;
public:
	AATributes();
	~AATributes();
};

#endif