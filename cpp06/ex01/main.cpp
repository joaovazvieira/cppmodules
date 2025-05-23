/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 14:03:04 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/14 14:04:04 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data* data = new Data("bob", 30);
	Data* point = new Data("joe", 20);

	std::cout << "\n" << *data << std::endl;
	std::cout << *point << std::endl;

	std::cout << "bob -> " << data << std::endl;
	std::cout << "joe -> " << point << std::endl;
	std::cout << "\n";
	
	uintptr_t serialize = Serializer::serialize(data);
	std::cout << "bob serialize -> " << serialize << std::endl;
	Data* deserialize = Serializer::deserialize(serialize);
	std::cout << "bob deserialize -> " << deserialize << std::endl;
	
	std::cout << "----------------" << "\n\n";
	
	uintptr_t serial = Serializer::serialize(point);
	std::cout << "bob serialize -> " << serial << std::endl;
	Data* deserial = Serializer::deserialize(serial);
	std::cout << "joe deserialize -> " << deserial << std::endl;
	
	delete data;
	delete point;
}