/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 14:00:01 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/26 15:47:41 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "Intern copied" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern fired" << std::endl;
}

Intern& Intern::operator=(const Intern& src)
{
	std::cout << "Intern assigned" << std::endl;
	(void)src;
	return (*this);
}

const char *Intern::FormNotFound::what() const throw()
{
	return ("Form not found");
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string	forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm*		form = NULL;
	int			i;

	for (i = 0; i < 3; i++)
	{
		if (name == forms[i])
			break ;
	}
	try
	{
		switch (i)
		{
			case 0:
				form = new ShrubberyCreationForm(target);
				break ;
			case 1:
				form = new RobotomyRequestForm(target);
				break ;
			case 2:
				form = new PresidentialPardonForm(target);
				break ;
			default:
				throw FormNotFound();
				break;
		}
		std::cout << "Intern creates " << form->getName() << std::endl;
		return (form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
	return (NULL);
}
