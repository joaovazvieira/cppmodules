#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << "\n";
}

Dog::Dog(const Dog& other) : Animal()
{
	*this = other;
	std::cout << "Dog copy constructor called" << "\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignation operator called" << "\n";
	this->_type = other.getType();
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << "\n";
}