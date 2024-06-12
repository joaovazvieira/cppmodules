#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:

		int					_rawBits;
		static const int	_bits;

	public:

		Fixed(void);
		Fixed(const Fixed& point);
		Fixed(const int intRaw);
		Fixed(const float floatRaw);
		~Fixed();
		Fixed& operator=(const Fixed& point);
		// arithemtic operators
		Fixed operator+(const Fixed& point) const;
		Fixed operator-(const Fixed& point) const;
		Fixed operator*(const Fixed& point) const;
		Fixed operator/(const Fixed& point) const;
		// comparison operators
		bool operator==(const Fixed& point) const;
		bool operator!=(const Fixed& point) const;
		bool operator>=(const Fixed& point) const;
		bool operator<=(const Fixed& point) const;
		bool operator<(const Fixed& point) const;
		bool operator>(const Fixed& point) const;
		// incremente and decrement operators
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		void	setRawBits(int const raw);

		static	Fixed& max(Fixed& p1, Fixed& p2);
		static	Fixed& min(Fixed& p1, Fixed& p2);
		static	const Fixed& max(Fixed const& p1, Fixed const& p2);
		static	const Fixed& min(Fixed const& p1, Fixed const& p2);
};

std::ostream& operator<<(std::ostream& op, const Fixed& point);

#endif