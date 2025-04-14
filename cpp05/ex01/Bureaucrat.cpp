/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 13:16:46 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/10 11:40:41 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor called" << "\n";
}
Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy._name), _grade(copy._grade){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &oldBureaucrat)
{
	if (this == &oldBureaucrat)
		return (*this);
	_grade = oldBureaucrat._grade;
	return (*this);
}

std::string const &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (out);
}

void Bureaucrat::signForm(Form *form)
{
	// if (form->getGradeSign() < _grade)
	// {
	// 	std::cout << _name << " cannot sign " << form->getName() << " because his grade is too low" << std::endl;
	// 	return ;
	// }
	try
	{
		form->beSigned(*this);
		std::cout << _name << " signs " << form->getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " cannot sign " << form->getName() << " because: " << e.what() << '\n';
	}
}
