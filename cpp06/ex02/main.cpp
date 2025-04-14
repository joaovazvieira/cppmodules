/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 16:07:10 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/14 14:42:28 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base* generate();
void identify(Base* p);
void identify(Base& p);

int main()
{
	std::srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < 4; ++i)
	{
	Base* base = generate();
	Base& ref = *base;

	identify(base);
	identify(ref);
	std::cout << "----------------" << "\n";

	delete base;
	}
	return 0;
}
