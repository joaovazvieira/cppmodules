#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << "\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other.getType())
{
	*this = other;
	std::cout << "WrongCat copy constructor called" << "\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat & other)
{
	std::cout << "WrongCat assignation operator called" << "\n";
	this->_type = other.getType();
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow Meow" << "\n";
}

std::string WrongCat::getType() const
{
	return this->_type;
}