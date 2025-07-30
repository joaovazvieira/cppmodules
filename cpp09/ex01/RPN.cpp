/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 10:01:23 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/30 09:46:35 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <functional>

struct Operations {
	std::string op;
	std::function<int(const int, const int)> func;
};

// if (ops.find(token) != ops.end())
// if (numbersStack.size() < 2) {
// 	std::cerr << "Error: Not enough operands for operation" << std::endl;
// 	return ;
// }
void RPN::calc(const std::string &input) {
	std::stack<int> numbersStack;
	std::istringstream iss(input);
	std::string token;

	Operations ops[] = {
		{"+", [](const int add1, const int add2) {return add1 + add2; }},
		{"-", [](const int sub1, const int sub2) {return sub1 - sub2; }},
		{"*", [](const int mul1, const int mul2) {return mul1 * mul2; }},
		{"/", [](const int div1, const int div2) {
			if (div2 == 0) throw std::runtime_error("Unable to divide by 0");
			return (div1 / div2);
		}}
	};

	const int numOps = sizeof(ops) / sizeof(ops[0]); // for array size

	if (input.empty()) {
		std::cerr << "Error: Empty input" << std::endl;
		return ;
	}
	while (iss >> token) {
		if (isdigit(token[0]) && token.length() == 1) {
			numbersStack.push(std::stoi(token)); // number go in stack
		} else {
			bool foundOp = false;
			for (int i = 0; i < numOps; i++) {
				if (ops[i].op == token) {
					foundOp = true;
					if (numbersStack.size() < 2) {
						throw std::runtime_error("Error: Not enough operands for operation");
						// std::cerr << "Error: Not enough operands for operation" << std::endl;
						return ;
					}
					int operand2 = numbersStack.top();
					numbersStack.pop();
					int operand1 = numbersStack.top();
					numbersStack.pop();
					// try {
						int result = ops[i].func(operand1, operand2);
						numbersStack.push(result);
					// } catch (const std::runtime_error &e) {
					// 	std::cerr << "Error: Invalid token '" << token << "'" << std::endl;
					// 	return ;
					// }
					break ;
				}
			}
			if (!foundOp) {
				std::cerr << "Error: invalid token '" << token << "'" << std::endl;
				return ;
			}
		}
	}
	if (numbersStack.size() != 1){
		std::cerr << "Error: Not enough operands or operations" << std::endl;
		return ;
	}
	std::cout << numbersStack.top() << std::endl;
}
