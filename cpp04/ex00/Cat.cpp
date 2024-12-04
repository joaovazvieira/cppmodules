#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << "\n";
}

Cat::Cat(const Cat& other) : Animal()
{
	*this = other;
	std::cout << "Cat copy constructor called" << "\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignation operator called" << "\n";
	this->_type = other.getType();
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << "\n";
}
