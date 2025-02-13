/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 14:10:38 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/06 15:20:06 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubbberyCreationForm::ShrubbberyCreationForm(std::string target): AForm("ShrubbberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubbberyCreationForm constructor called" << std::endl;
}

ShrubbberyCreationForm::ShrubbberyCreationForm(const ShrubbberyCreationForm& src): AForm(src)
{
	std::cout << "ShrubbberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubbberyCreationForm::~ShrubbberyCreationForm()
{
	std::cout << "ShrubbberyCreationForm destructor called" << std::endl;
}

ShrubbberyCreationForm& ShrubbberyCreationForm::operator=(const ShrubbberyCreationForm& src)
{
	std::cout << "ShrubbberyCreationForm assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	AForm::operator=(src);
	return (*this);
}

void ShrubbberyCreationForm::Execute(const Bureaucrat &executor) const
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

std::string ShrubbberyCreationForm::getTarget() const
{
	return (_target);
}

std::ostream &operator<<(std::ostream &output, const ShrubbberyCreationForm &src)
{
	output << "AForm name: " << src.getName() << std::endl;
	output << "Sign grade: " << src.getGradeSign() << std::endl;
	output << "Execute grade: " << src.getGradeExecute() << std::endl;
	output << "Is signed: " << src.getSigned() << std::endl;
	output << "Target: " << src.getTarget() << std::endl;
	return (output);
}
