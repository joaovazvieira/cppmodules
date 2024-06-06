#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:

		int					_rawBits;
		static const int	_bits;

	public:

		Fixed(void);
		Fixed(const Fixed& point);
		Fixed & operator=(const Fixed &point);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif