/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 13:24:46 by jovieira      #+#    #+#                 */
/*   Updated: 2025/03/13 14:12:10 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(std::string name, int age): _name(name), _age(age)
{
	std::cout << "Default constructor" << std::endl;
}

Data::Data(const Data& copy, int age): _name(copy._name), _age(age)
{
	std::cout << "copy constructor" << std::endl;
}

Data::~Data(){}

Data &Data::operator=(const Data& other)
{
	if (this == &other)
		return (*this);
	_name = other._name;
	return (*this);
}

std::string const &Data::getName() const
{
	return (_name);
}

int Data::getAge() const
{
	return (_age);
}

std::ostream &operator<<(std::ostream &src, Data const &out)
{
	src << out.getName() << ", is " << out.getAge() << " years old" << std::endl;
	return (src);
}