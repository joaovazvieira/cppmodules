/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/17 17:17:41 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/17 18:16:59 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
// #pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	private:
		T* 				_array;
		unsigned int 	_aSize;
	
	public:
		Array();
		Array(unsigned int size);
		Array(const Array& copy);
		~Array();

		Array& operator=(const Array& src);

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		
		unsigned int size() const;
};

#include "Array.tpp"

#endif