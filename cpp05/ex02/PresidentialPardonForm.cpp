/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 12:36:47 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/06 15:04:21 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	this->_target = copy._target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	AForm::operator=(copy);
	return (*this);
}

void PresidentialPardonForm::Execute(Bureaucrat const &executor) const
{
	// AForm::Execute(executor);
	if (this->getSigned() == false)
		throw FormNoSignedexception();
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &output, const PresidentialPardonForm &src)
{
	output << "AForm name: " << src.getName() << std::endl;
	output << "Sign grade: " << src.getGradeSign() << std::endl;
	output << "Execute grade: " << src.getGradeExecute() << std::endl;
	output << "Is signed: " << src.getSigned() << std::endl;
	output << "Target: " << src.getTarget() << std::endl;
	return (output);
}
