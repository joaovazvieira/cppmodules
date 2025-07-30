/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 09:36:02 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/30 09:17:45 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>
#include <cstring>
#include <iostream>

class RPN {
	
	public:
		RPN() = default;
		RPN(const RPN &src) = default;
		~RPN() = default;
		RPN &operator=(const RPN &src) = default;
		static void	calc(const std::string &input);
		
		class invalidExpression : public std::exception {
			const char* what() const throw() { return "Invalid RPN Expression"; }
		};
	
};

#endif