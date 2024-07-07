#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << "\n";
}

AAnimal::AAnimal(const AAnimal& other)
{
	*this = other;
	std::cout << "AAnimal copy constructor called" << "\n";
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << "\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal assignation operator called" << "\n";
	this->_type = other.getType();
	return *this;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal sound" << "\n";
}

std::string AAnimal::getType() const
{
	return this->_type;
}
