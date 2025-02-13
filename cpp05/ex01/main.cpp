/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 14:38:17 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/05 17:55:43 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
	Bureaucrat bob("bob", 150);
	std::cout << bob << "\n";
	Bureaucrat jim("jim", 1);
	std::cout << jim << "\n";
	
	Form default_Form;
	std::cout << default_Form << "\n";
	Form form("form", 1, 1);
	std::cout << form << "\n";
	try
	{
		Form form2("form2", 1, 0);
		std::cout << form2 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n";
	try {
		Form form3("form3", 1, 155);
		std::cout << form3 << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n";
	Form	form4("form4", 150, 1);
	Form	form5("form5", 150, 150);
	Form	form6("form6", 1, 150);

	std::cout << "\n";
	
	bob.signForm(&form);
	bob.signForm(&default_Form);
	jim.signForm(&form);
	jim.signForm(&default_Form);

	std::cout << "\n";

	Form form7(form);
	std::cout << form7 << "\n";
	form7 = form5;
	std::cout << form7 << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}