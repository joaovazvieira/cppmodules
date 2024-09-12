#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(): _rawBits(0)
{
	// std::cout << "Default constructor called" << "\n";
}

Fixed::Fixed(const Fixed& point)
{
	// std::cout << "Copy constructor called" << "\n";
	// _rawBits = point.getRawBits();
	*this = point;
}

Fixed::Fixed(const int intRaw)
{
	_rawBits = intRaw * (1 << _bits);
	// std::cout << "Int constructor called" << "\n";
}

Fixed::Fixed(const float floatRaw)
{
	_rawBits = roundf(floatRaw * (1 << _bits));
	// std::cout << "Float constructor called" << "\n";
}

Fixed& Fixed::operator=(const Fixed &point)
{
	// std::cout << "Copy assignation operator called" << "\n";
	_rawBits = point.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << "\n";
}

int Fixed::toInt(void) const { return _rawBits >> _bits; }

float Fixed::toFloat(void) const { return (float)getRawBits() / (1 << _bits); }
// coverts the fixed-point number to a floating-point number, if getRawBits resturns 256, it will return 1.0
int Fixed::getRawBits(void) const { return _rawBits; }

void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

std::ostream& operator<<(std::ostream& op, const Fixed& point)
{
	op << point.toFloat();
	return op;
}

// arithemtic operator

Fixed Fixed::operator+(const Fixed& point) const
{
	Fixed	add;

	add.setRawBits(this->getRawBits() + point.getRawBits());
	return add;
}

Fixed Fixed::operator-(const Fixed& point) const
{
	Fixed	sub;

	sub.setRawBits(this->getRawBits() - point.getRawBits());
	return sub;
}

Fixed Fixed::operator*(const Fixed& point) const
{
	Fixed	mult;

	mult.setRawBits(this->getRawBits() * point.getRawBits() / (1 << _bits));
	return mult;
}

Fixed Fixed::operator/(const Fixed& point) const
{
	Fixed	div;

	div.setRawBits((this->getRawBits() << _bits) / point.getRawBits());
	return div;
}

// comparison operators

bool Fixed::operator==(const Fixed& point) const
{
	return this->getRawBits() == point.getRawBits();
}

bool Fixed::operator!=(const Fixed& point) const
{
	return this->getRawBits() != point.getRawBits();
}

bool Fixed::operator>=(const Fixed& point) const
{
	return this->getRawBits() >= point.getRawBits();
}

bool Fixed::operator<=(const Fixed& point) const
{
	return this->getRawBits() <= point.getRawBits();
}

bool Fixed::operator<(const Fixed& point) const
{
	return this->getRawBits() < point.getRawBits();
}

bool Fixed::operator>(const Fixed& point) const
{
	return this->getRawBits() > point.getRawBits();
}

// increment and decrement operators
// operator increment or decrement the value by 1
Fixed& Fixed::operator++(void)
{
	_rawBits++;
	return *this;
}

Fixed& Fixed::operator--(void)
{
	_rawBits--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	prev = *this;
	_rawBits++;
	return prev;
}
Fixed Fixed::operator--(int)
{
	Fixed	prev = *this;
	_rawBits--;
	return prev;
}

// static member functions min/max

Fixed& Fixed::max(Fixed& p1, Fixed& p2)
{
	return (p1 > p2 ? p1:p2);
}

Fixed& Fixed::min(Fixed& p1, Fixed& p2)
{
	return (p1 < p2 ? p1:p2);
}

const Fixed& Fixed::max(Fixed const& p1, Fixed const& p2)
{
	return (p1 > p2 ? p1:p2);
}

const Fixed& Fixed::min(Fixed const& p1, Fixed const& p2)
{
	return (p1 < p2 ? p1:p2);
}