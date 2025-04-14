/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 13:06:01 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/10 11:48:31 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int 				_grade;
	
		
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();
		
		Bureaucrat &operator=(Bureaucrat const &oldBureauvrat);
		std::string const &getName() const;
		int getGrade() const;
		
		void incrementGrade();
		void decrementGrade();
		void signForm(Form *form);
		
		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b);

#endif