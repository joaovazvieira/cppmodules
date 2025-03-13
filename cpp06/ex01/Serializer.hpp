/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/03 14:25:29 by jovieira      #+#    #+#                 */
/*   Updated: 2025/03/13 15:23:01 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEREIALIZER_HPP
#define SEREIALIZER_HPP

#include "Data.hpp"
#include <iostream>

typedef unsigned long uintptr_t;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const& src);
		~Serializer();
	
		Serializer& operator=(Serializer const& src);
		
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};


#endif