/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/13 15:52:33 by jovieira      #+#    #+#                 */
/*   Updated: 2025/03/13 16:23:09 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base()
{
	// std::cout << "deconstructor called" << std::endl;
}

Base* generate()
{
	srand(time(NULL));
	//r for random
	int r = rand() % 3;
	
	switch (r) {
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A was called" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B was called" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C was called" << std::endl;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception& e)
	{
		(void)e;
		try {
			B& b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b;
		}
		catch (std::exception& e)
		{
			try {
				C& c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void)c;
			}
		catch (std::exception& e)
		{
			std::cout << "Unable to catch A, B or C" << std::endl;
		}
		}
	}
}