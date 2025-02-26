/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 14:10:38 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/26 15:49:24 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src): AForm(src)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	return (*this);
}

void ShrubberyCreationForm::Execute(const Bureaucrat &executor) const
{
	if(this->getSigned() == false)
		throw FormNoSignedexception();
	if (executor.getGrade() > this->getGradeExecute())
		throw GradeTooLowException();
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error opening file");
	
	
	// file.open(filename);
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
	file.close();
	std::cout << "Shrubbery has been created" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

std::ostream &operator<<(std::ostream &output, const ShrubberyCreationForm &src)
{
	output << "AForm name: " << src.getName() << std::endl;
	output << "Sign grade: " << src.getGradeSign() << std::endl;
	output << "Execute grade: " << src.getGradeExecute() << std::endl;
	output << "Is signed: " << src.getSigned() << std::endl;
	output << "Target: " << src.getTarget() << std::endl;
	return (output);
}
