/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/06 12:48:36 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/06 15:01:44 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string const	_target;
		
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		virtual ~RobotomyRequestForm();
		
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
		
		void	Execute(const Bureaucrat &executor) const;
		std::string	getTarget() const;
};

std::ostream &operator<<(std::ostream &output, const RobotomyRequestForm &src);

#endif