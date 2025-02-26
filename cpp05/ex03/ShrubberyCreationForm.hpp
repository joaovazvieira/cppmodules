/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 14:10:40 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/26 14:16:53 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string const	_target;

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		virtual ~ShrubberyCreationForm();
		
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
		
		void	Execute(const Bureaucrat &executor) const;
		std::string	getTarget() const;
};

std::ostream &operator<<(std::ostream &output, const ShrubberyCreationForm &src);

#endif