/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/27 12:51:47 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/10 16:27:05 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		return (1);
	}

	std::cout << "----------Input-----------" << std::endl;
	ScalarConverter::convert(argv[1]);
	std::cout << "--------------------------\n" << std::endl;

	// std::cout << "----------Tests-----------" << std::endl;
	// ScalarConverter::convert("nan");
	// std::cout << std::endl;
	// ScalarConverter::convert("nanf");
	// std::cout << std::endl;
	// ScalarConverter::convert("inf");
	// std::cout << std::endl;
	// ScalarConverter::convert("inff");
	// std::cout << std::endl;
	// ScalarConverter::convert("+inf");
	// std::cout << std::endl;
	// ScalarConverter::convert("+inff");
	// std::cout << std::endl;
	// ScalarConverter::convert("-inf");
	// std::cout << std::endl;
	// ScalarConverter::convert("-inff");
	// std::cout << std::endl;
	// ScalarConverter::convert("0");
	// std::cout << std::endl;
	// ScalarConverter::convert("0.1");
	// std::cout << std::endl;
	// ScalarConverter::convert("1.0f");
	// std::cout << std::endl;
	// ScalarConverter::convert("2.f");
	// std::cout << std::endl;
	// ScalarConverter::convert(".2f");
	// std::cout << std::endl;
	// ScalarConverter::convert("a");
	// std::cout << std::endl;
	// ScalarConverter::convert("42");
	// std::cout << std::endl;
	// ScalarConverter::convert("42.0");
	// std::cout << std::endl;
	// ScalarConverter::convert("-42.0f");
	// std::cout << std::endl;
	// ScalarConverter::convert(" ");
	// std::cout << "--------------------------\n" << std::endl;
	
	return (0);
}