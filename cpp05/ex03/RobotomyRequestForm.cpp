/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 12:49:55 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/06 15:20:03 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	// this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): AForm(src)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	return (*this);
}

void RobotomyRequestForm::Execute(const Bureaucrat &executor) const
{
	if(this->getSigned() == false)
		throw FormNoSignedexception();
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::cout << "* some drilling noises *" << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized sucessfully" << std::endl;
	else
		std::cout << "the robotomization has failed" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

std::ostream &operator<<(std::ostream &output, const RobotomyRequestForm &src)
{
	output << "AForm name: " << src.getName() << std::endl;
	output << "Sign grade: " << src.getGradeSign() << std::endl;
	output << "Execute grade: " << src.getGradeExecute() << std::endl;
	output << "Is signed: " << src.getSigned() << std::endl;
	output << "Target: " << src.getTarget() << std::endl;
	return (output);
}
