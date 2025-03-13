/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 16:07:10 by jovieira      #+#    #+#                 */
/*   Updated: 2025/03/13 16:22:28 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main()
{
	// srand(time(0));

	// for (int i = 0; i < 5; ++i)
	// {
	// 	Base* obj = generate();
		
	// 	std::cout << "Identify with pointer: ";
	// 	identify(obj);

	// 	std::cout << "Identify with reference: ";
	// 	identify(*obj);

	// 	delete obj;
	// }
	for (int i = 0; i < 4; ++i)
	{
	Base* base = generate();
	Base& ref = *base;

	identify(base);
	identify(ref);

	delete base;
	}
	return 0;
}
