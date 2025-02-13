/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 14:10:40 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/06 14:41:34 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubbberyCreationForm_HPP
#define ShrubbberyCreationForm_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubbberyCreationForm: public AForm
{
	private:
		std::string const	_target;

	public:
		ShrubbberyCreationForm(std::string target);
		ShrubbberyCreationForm(const ShrubbberyCreationForm& src);
		virtual ~ShrubbberyCreationForm();
		
		ShrubbberyCreationForm& operator=(const ShrubbberyCreationForm& src);
		
		void	Execute(const Bureaucrat &executor) const;
		std::string	getTarget() const;
};

std::ostream &operator<<(std::ostream &output, const ShrubbberyCreationForm &src);

#endif