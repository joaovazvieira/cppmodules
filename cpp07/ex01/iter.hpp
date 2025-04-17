/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/17 16:18:48 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/17 16:35:59 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&)){
	for(size_t i = 0; i < length; ++i){
		func(array[i]);
	}
}

template <typename T>
void printElement(T& elem){
	std::cout << elem << std::endl;
}

#endif