/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 12:31:31 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/06 14:24:46 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
		
		void Execute(const Bureaucrat &executor) const;
		std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &output, const PresidentialPardonForm &src);

#endif