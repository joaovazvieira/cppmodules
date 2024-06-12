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

Fixed::Fixed(const int intRaw)
{
	_rawBits = intRaw * (1 << _bits);
	std::cout << "Int constructor called" << "\n";
}

Fixed::Fixed(const float floatRaw)
{
	_rawBits = roundf(floatRaw * (1 << _bits));
	std::cout << "Float constructor called" << "\n";
}

Fixed& Fixed::operator=(const Fixed &point)
{
	std::cout << "Copy assignation operator called" << "\n";
	_rawBits = point.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << "\n";
}

int Fixed::toInt(void) const { return _rawBits >> _bits; }

float Fixed::toFloat(void) const { return (float)getRawBits() / (1 << _bits); }

int Fixed::getRawBits(void) const { return _rawBits; }

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

std::ostream& operator<<(std::ostream& op, const Fixed& point)
{
	op << point.toFloat();
	return op;
}