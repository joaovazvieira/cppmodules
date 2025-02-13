/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/06 13:39:10 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/06 13:56:02 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const 			_gradeSign;
		int const 			_gradeExecute;
		
		void	_checkHigh(int grade);
		void	_checkLow(int grade);
		
	
	public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExecute);
		AForm(const AForm& src);
		virtual ~AForm();
		
		AForm& operator=(const AForm& src);
		
		std::string const &getName() const;
		bool 	getSigned() const;
		int 	getGradeSign() const;
		int 	getGradeExecute() const;
		
		void beSigned(const Bureaucrat& src);
		virtual void Execute(const Bureaucrat &executor) const = 0;

		class IsSigned: public std::exception
		{
			virtual const char* what() const throw();
		};
		
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
};

std::ostream &operator<<(std::ostream &out, AForm const &f);

#endif