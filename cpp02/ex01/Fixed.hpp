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
		Fixed & operator=(const Fixed &point);


		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& op, const Fixed& point);

#endif