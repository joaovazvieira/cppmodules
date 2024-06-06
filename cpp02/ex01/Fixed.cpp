#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(): _rawBits(0)
{
	std::cout << "Default constructor called" << "\n";
}

Fixed::Fixed(const Fixed& point)
{
	std::cout << "Copy constructor called" << "\n";
	// _rawBits = point.getRawBits();
	*this = point;
}

Fixed& Fixed::operator=(const Fixed &point)
{
	std::cout << "Assignation operator called" << "\n";
	this->_rawBits = point.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << "\n";
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

