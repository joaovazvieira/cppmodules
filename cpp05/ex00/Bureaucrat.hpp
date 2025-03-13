/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 13:06:01 by jovieira      #+#    #+#                 */
/*   Updated: 2025/03/12 14:51:43 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		std::string const 	_name;
		int					_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();
		
		Bureaucrat &operator=(const Bureaucrat& other);
		
		std::string const	&getName() const;
		int					getGrade() const;
		
		void	incrementGrade();
		void	decrementGrade();
		
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