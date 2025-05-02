/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 16:13:56 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/02 11:48:23 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Parse.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default Constructor" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "Copy Constructor" << std::endl;
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const &src)
{
	std::cout << "Assignation Operator" << std::endl;
	(void)src;
	return *this;
}

void	ScalarConverter::convert(std::string input)
{
	std::cout << "Converting\n" << std::endl;
	if (isInt(input))
		printInt(input);
	else if (isChar(input))
		printChar(input);
	else if (isFloat(input))
		printFloat(input);
	else if (isDouble(input))
		printDouble(input);
	else if (isPseudoLiteral(input))
		printPseudoLiteral(input);
	else
		std::cerr << "Error: \"" << input << "\" : Invalid Input" << std::endl;
}
