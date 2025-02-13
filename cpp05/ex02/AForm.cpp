/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 13:39:06 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/06 14:30:19 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():_name("default"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "Form default constructor called" << "\n";
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute):_name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << "Form constructor called" << "\n";
	this->_checkHigh(this->_gradeSign);
	this->_checkLow(this->_gradeSign);
	this->_checkHigh(this->_gradeExecute);
	this->_checkLow(this->_gradeExecute);
}

AForm::AForm(const AForm& src):_name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute)
{
	std::cout << "Form copy constructor called" << "\n";
	*this = src;
}

AForm::~AForm()
{
	// std::cout << "Form destructor called" << "\n";
}

AForm& AForm::operator=(const AForm& src)
{
	std::cout << "Form assignation operator called" << "\n";
	if (this == &src)
		return (*this);
	_signed = src._signed;
	return (*this);
}

std::string const &AForm::getName() const
{
	return (_name);
}


void	AForm::_checkHigh(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
}

void	AForm::_checkLow(int grade)
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeSign() const
{
	return (_gradeSign);
}

int AForm::getGradeExecute() const
{
	return (_gradeExecute);
}

void AForm::beSigned(const Bureaucrat& src)
{
	if (this->getSigned())
		throw AForm::IsSigned();
	if (src.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char *AForm::IsSigned::what() const throw()
{
	return ("Form is already signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNoSignedexception::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
	out << "Form name: " << f.getName() << "\n";
	out << "Form sign grade: " << f.getGradeSign() << "\n";
	out << "form grade to execute: " << f.getGradeExecute() << "\n";
	out << "Form is signed: " << f.getSigned() << std::endl;
	return (out);
}

