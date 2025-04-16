/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FunctionTemplate.hpp                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/14 15:14:00 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/14 15:27:38 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONTEMPLATE_HPP
#define FUNCTIONTEMPLATE_HPP

template <typename T>
T min(const T &a, const T &b){
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(const T &a, const T &b){
	if (a > b)
		return a;
	return b;
}

template <typename T>
T swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
	return a;
}

#endif