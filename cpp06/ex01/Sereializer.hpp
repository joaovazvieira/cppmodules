/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Sereializer.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/03 14:25:29 by jovieira      #+#    #+#                 */
/*   Updated: 2025/03/03 14:42:15 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEREIALIZER_HPP
#define SEREIALIZER_HPP

#include "Data.hpp"
#include <iostream>

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const& src);
		~Serializer();
	
		Serializer& operator=(Serializer const& src);
		
	public:
		static uintptr_t serialize(Data* ptr)
		{
			return reinterpret_cast<uintptr_t>(ptr);
		}
		static Data* deserialize(uintptr_t raw)
		{
			return reinterpret_cast<Data*>(raw);
		}
		
};


#endif