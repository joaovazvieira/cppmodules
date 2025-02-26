/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 14:38:17 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/26 15:54:31 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat james("james", 1);
	std::cout << james << std::endl;
	Bureaucrat Bond("Bond", 150);
	std::cout << Bond << std::endl;
	
	Intern	someRandomIntern;
	AForm*	form1 = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
	std::cout << *form1 << std::endl;
	james.signForm(form1);
	james.executeForm(*form1);
	Bond.signForm(form1);
	Bond.executeForm(*form1);
	delete form1;

	std::cout << std::endl;

	AForm*	form2 = someRandomIntern.makeForm("RobotomyRequestForm", "Joe");
	std::cout << *form2 << std::endl;
	james.signForm(form2);
	james.executeForm(*form2);
	Bond.signForm(form2);
	Bond.executeForm(*form2);
	delete form2;

	std::cout << std::endl;

	AForm*	form4 = someRandomIntern.makeForm("RobotomyRequestForm", "Joe");
	std::cout << *form4 << std::endl;
	james.signForm(form4);
	james.executeForm(*form4);
	Bond.signForm(form4);
	Bond.executeForm(*form4);
	delete form4;

	std::cout << std::endl;

	AForm*	form3 = someRandomIntern.makeForm("ShrubberyCreationForm", "Home");
	std::cout << *form3 << std::endl;
	james.signForm(form3);
	james.executeForm(*form3);
	Bond.signForm(form3);
	Bond.executeForm(*form3);
	delete form3;

	return (0);
}