/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 10:01:23 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/23 11:54:27 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <map>

typedef int (*CalcFunc)(const int, const int);

void RPN::calc(const std::string &input) {
	std::stack<int> numbersStack;
	std::istringstream iss(input);
	std::string token;

	std::map<std::string, CalcFunc> ops = {
		{"+", &RPN::_add},
		{"-", &RPN::_sub},
		{"*", &RPN::_mul},
		{"/", &RPN::_div}
	};

	if (input.empty()) {
		std::cerr << "Error: Empty input" << std::endl;
		return ;
	}
	int numCount = 0;
	int opCount = 0;
	while (iss >> token) {
		if (isdigit(token[0])) {
			numbersStack.push(std::stoi(token)); // number go in stack
			numCount++;
		} else if (ops.find(token) != ops.end()) {
				if (numbersStack.size() < 2) {
					std::cerr << "Error: Not enough operands for operation" << std::endl;
					return ;
				}
				opCount++;
				int operand2 = numbersStack.top();
				numbersStack.pop();
				int operand1 = numbersStack.top();
				numbersStack.pop();
				int result = ops[token](operand1, operand2);
				numbersStack.push(result);
		} else {
			std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
			return ;
		}
	}
	if ((numCount < 2 && opCount < 1 ) || numbersStack.size() != 1) {
		std::cerr << "Error: Not enough operands or operations" << std::endl;
		return ;
	}
	std::cout << numbersStack.top() << std::endl;
}
