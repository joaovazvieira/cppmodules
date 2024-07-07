#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << "\n";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal type constructor called" << "\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	*this = other;
	std::cout << "WrongAnimal copy constructor called" << "\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << "\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal assignation operator called" << "\n";
	this->_type = other.getType();
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << "\n";
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}
