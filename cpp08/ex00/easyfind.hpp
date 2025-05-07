/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/01 14:35:05 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/02 13:34:45 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <list>

class NotFoundexcpetion : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("Unable to found element");
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int input)
{
	typename T::iterator it = std::find(container.begin(), container.end(), input);
	if (it == container.end())
		throw (NotFoundexcpetion());
	return it;
}

#endif