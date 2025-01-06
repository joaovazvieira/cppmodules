/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 13:39:06 by jovieira      #+#    #+#                 */
/*   Updated: 2025/01/06 15:06:02 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_name("default"), _signed(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "Form default constructor called" << "\n";
}

Form::Form(std::string name, int gradeSign, int gradeExecute):_name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << "Form constructor called" << "\n";
	this->_checkHigh(this->_gradeSign);
	this->_checkLow(this->_gradeSign);
	this->_checkHigh(this->_gradeExecute);
	this->_checkLow(this->_gradeExecute);
}

Form::Form(const Form& src):_name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExecute(src._gradeExecute)
{
	std::cout << "Form copy constructor called" << "\n";
	*this = src;
}

Form::~Form()
{
	std::cout << "Form destructor called" << "\n";
}

Form& Form::operator=(const Form& src)
{
	std::cout << "Form assignation operator called" << "\n";
	if (this == &src)
		return (*this);
	_signed = src._signed;
	return (*this);
}

std::string const &Form::getName() const
{
	return (_name);
}

// void	Form::_checkGrade(int grade)
// {
// 	if (grade < 1)
// 		throw Form::GradeTooHighException();
// 	if (grade > 150)
// 		throw Form::GradeTooLowException();
// }

void	Form::_checkHigh(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
}

void	Form::_checkLow(int grade)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeSign() const
{
	return (_gradeSign);
}

int Form::getGradeExecute() const
{
	return (_gradeExecute);
}

void Form::beSigned(const Bureaucrat& src)
{
	if (src.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* Form::FormNoSignedexception::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
	out << "Form name: " << f.getName() << "\n";
	out << "Form sign grade: " << f.getGradeSign() << "\n";
	out << "form grade to execute: " << f.getGradeExecute() << "\n";
	out << "Form is signed: " << f.getSigned() << std::endl;
	return (out);
}
