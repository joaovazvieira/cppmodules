/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 14:38:17 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/05 12:31:36 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Jovieira", 3);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("Jovieira", 149);
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}