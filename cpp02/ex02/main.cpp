#include "Fixed.hpp"

int main( void ) 
{
	{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		Fixed	a(3);
		Fixed	b(10);
		
		std::cout << "" << std::endl;
		std::cout << b + a << std::endl;
		std::cout << b - a << std::endl;
		std::cout << b * a << std::endl;
		std::cout << b / a << std::endl;
		// std::cout << b % a << std::endl;
	}
	{
		Fixed	a(3.25f);
		Fixed	b(10.5f);
		
		std::cout << "" << std::endl;
		std::cout << b + a << std::endl;
		std::cout << b - a << std::endl;
		std::cout << b * a << std::endl;
		std::cout << b / a << std::endl;
		// std::cout << b % a << std::endl;
	}
return 0;
}