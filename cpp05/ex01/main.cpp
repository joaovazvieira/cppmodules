/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 14:38:17 by jovieira      #+#    #+#                 */
/*   Updated: 2025/01/06 15:07:41 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat bob("bob", 1);
	std::cout << bob << "\n";
	Bureaucrat jim("jim", 150);
	std::cout << jim << "\n";
	
	Form default_Form;
	std::cout << default_Form << "\n";
	Form form("form", 1, 1);
	std::cout << form << "\n";
	Form form2("form2", 1, 150);
	std::cout << form2 << "\n";

	Form	form3("form3", 1, 1);
	Form	form4("form4", 150, 1);
	Form	form5("form5", 1, 1);
	Form	form6("form6", 1, 150);

	std::cout << "\n";
	
	bob.signForm(&form);
	bob.signForm(&default_Form);
	jim.signForm(&form);
	jim.signForm(&default_Form);

	std::cout << "\n";

	Form form7(form);
	std::cout << form7 << "\n";
	form7 = form2;
	std::cout << form7 << "\n";
	return (0);
}