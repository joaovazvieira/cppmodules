/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 09:36:02 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/22 10:43:35 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>
#include <cstring>
#include <iostream>

class RPN {
	
	private:
	
	static int	_add(const int add1, const int add2) {return add1 + add2; };
	static int	_sub(const int sub1, const int sub2) {return sub1 - sub2; };
	static int	_mul(const int mul1, const int mul2) {return mul1 * mul2; };
	static int	_div(const int div1, const int div2) {
		if (div2 == 0) throw std::runtime_error("Unable to divide by 0");
		return (div1 / div2);
	};
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