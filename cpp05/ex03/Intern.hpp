/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:55:00 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/26 15:47:49 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();
		
		Intern& operator=(const Intern& src);
		
		AForm* makeForm(std::string name, std::string target);
		
		class FormNotFound : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif