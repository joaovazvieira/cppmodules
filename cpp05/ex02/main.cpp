/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 14:38:17 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/06 15:22:46 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

	std::cout << "---------------------" << "\n\n";

	PresidentialPardonForm form1("Man");
	std::cout << form1 << std::endl;
	Bond.signForm(&form1);
	Bond.executeForm(form1);
	james.signForm(&form1);
	james.executeForm(form1);
	
	std::cout << "---------------------" << "\n\n";
	{
	RobotomyRequestForm form2("Jay");
	std::cout << form2 << std::endl;
	Bond.signForm(&form2);
	Bond.executeForm(form2);
	james.signForm(&form2);
	james.executeForm(form2);
	}
	std::cout << "---------------------" << "\n\n";
	{
	RobotomyRequestForm form2("Jay");
	std::cout << form2 << std::endl;
	Bond.signForm(&form2);
	Bond.executeForm(form2);
	james.signForm(&form2);
	james.executeForm(form2);
	}
	std::cout << "---------------------" << "\n\n";
	
	ShrubbberyCreationForm form3("joe");
	std::cout << form3 << std::endl;
	Bond.signForm(&form3);
	Bond.executeForm(form3);
	james.signForm(&form3);
	james.executeForm(form3);
	
	std::cout << "\n";
	return (0);
}