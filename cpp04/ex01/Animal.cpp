#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << "\n";
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal copy constructor called" << "\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << "\n";
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignation operator called" << "\n";
	this->_type = other.getType();
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << "\n";
}

std::string Animal::getType() const
{
	return this->_type;
}
