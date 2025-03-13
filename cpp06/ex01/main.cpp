/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 14:03:04 by jovieira      #+#    #+#                 */
/*   Updated: 2025/03/13 15:12:29 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data* data = new Data("bob", 30);
	Data* point = new Data("joe", 20);

	std::cout << "\n" << *data << std::endl;
	std::cout << "\n" << *point << std::endl;

	uintptr_t serialize = Serializer::serialize(data);
	Data* deserialize = Serializer::deserialize(serialize);

	uintptr_t serial = Serializer::serialize(point);
	Data* deserial = Serializer::deserialize(serial);

	// std::cout << *deserialize << std::endl;

	std::cout << data << std::endl;
	std::cout << point << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << deserialize << std::endl;
	std::cout << deserial << std::endl;
	
	delete data;
	delete point;
}