#include "Point.hpp"

int main( void ) 
{
	{
		Point	a(5.0f, 3.0f);
		Point	b(3.0f, 5.0f);
		Point	c(1.0f, 3.0f);
		Point	d(3.0f, 1.0f);
	
		std::cout << "Case 1 is " << (bsp(a, b, c, d) ? "True":"False") << "\n" << std::endl;
	}
	{	
		Point		a(3.0f, 4.0f);
		Point		b(6.0f, 8.0f);
		Point		c(5.0f, 2.0f);
		Point		d(-4.0f, -4.0f);

		std::cout << "Case 2 is " << (bsp(a, b, c, d) ? "True":"False") << "\n" << std::endl;
	}
	{	
		Point		a(3.0f, 4.0f);
		Point		b(3.0f, 4.0f);
		Point		c(3.0f, 4.0f);
		Point		d(3.0f, 4.0f);

		std::cout << "Case 3 is " << (bsp(a, b, c, d) ? "True":"False") << "\n" << std::endl;
	}
	{	
		Point		a(3.0f, 1.0f);
		Point		b(3.0f, 3.0f);
		Point		c(3.0f, 7.0f);
		Point		d(3.0f, 5.0f);

		std::cout << "Case 4 is " << (bsp(a, b, c, d) ? "True":"False") << "\n" << std::endl;
	}
	{
		Point a(0.0f, 0.0f);
		Point b(5.0f, 0.0f);
		Point c(2.5f, 4.33f);
		Point d(3.0f, 2.0f);

		std::cout << "Case 5 is " << (bsp(a, b, c, d) ? "True":"False") << "\n" << std::endl;
	}
	{	
		Point a(-3.0f, -2.0f);
		Point b(1.0f, 3.0f);
		Point c(5.0f, -1.0f);
		Point d(3.0f, 4.0f);

		std::cout << "Case 6 is " << (bsp(a, b, c, d) ? "True":"False") << "\n" << std::endl;
	}
	{	
		Point a(1.0f, 1.0f);
		Point b(5.0f, 1.0f);
		Point c(3.0f, 5.0f);
		Point d(3.0f, 2.0f);

		std::cout << "Case 7 is " << (bsp(a, b, c, d) ? "True":"False") << "\n" << std::endl;
	}
	return (0);
}