/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 13:39:10 by jovieira      #+#    #+#                 */
/*   Updated: 2025/01/06 15:03:33 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const 			_gradeSign;
		int const 			_gradeExecute;
		
		// void _checkGrade(int grade);
		void	_checkHigh(int grade);
		void	_checkLow(int grade);
		
		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};
		
		class FormNoSignedexception: public std::exception
		{
			virtual const char* what() const throw();
		};
	
	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExecute);
		Form(const Form& src);
		~Form();
		
		Form& operator=(const Form& src);
		
		std::string const &getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		
		void beSigned(const Bureaucrat& src);
};

std::ostream &operator<<(std::ostream &out, Form const &f);

#endif