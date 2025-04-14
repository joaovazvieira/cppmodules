/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Parse.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/27 12:13:00 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/14 12:27:14 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"
#include <sstream>

bool	isInt(std::string input)
{
	if (input.empty())
		return false;
	if (input[0] == '+' || input[0] == '-')
		if (input.length() == 0)
			return false;
	for (size_t i = 0; i < input.length(); i++)
		if (!isdigit(input[i]))
			return false;
	return true;
}

bool	isChar(std::string input)
{
	int	c = static_cast<int>(input[0]);
	if (input.length() != 1)
		return false;
	if (c < 0 || c > 127)
		return false;
	return true;
}

bool isFloat(std::string input)
{
	if (input[0] != '+' && input[0] != '-' && !isdigit(input[0]))
		return false;
	if (input.back() != 'f' || input.empty())
		return false;
	int i = 0;
	for (char ch : input)
	{
		if (ch == '.')
			if (++i > 1)
				return false;
	}
	if (input.find_first_not_of("0123456789.f", 1) != std::string::npos)
		return false;
	return true;
}

bool isDouble(std::string input)
{
	if ((input[0] != '+' && input[0] != '-' && !isdigit(input[0])) || input.empty())
		return false;
	int i = 0;
	for (char ch : input)
	{
		if (ch == '.')
			if (++i > 1)
				return false;
	}
	if (input.find_first_not_of("0123456789.", 1) != std::string::npos)
		return false;
	return true;
}

bool isPseudoLiteral(std::string input)
{
	if (input == "nan" || input == "nanf" || input == "inf" || input == "-inf" \
	|| input == "inff" || input == "-inff"|| input == "+inf" || input == "+inff")
		return (true);
	return (false);
}

void	printInt(std::string input)
{
	std::stringstream ss(input);
	int i;
	ss >> i;
	if (isprint(i))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else if (i < 0 || i > 127)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	printChar(std::string input)
{
	int c = input[0];
	if (isprint(c))
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	else if (c < 0 || c > 127)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << c << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printFloat(std::string input)
{
	std::stringstream ss(input);
	float f;
	
	ss >> f;
	if (isprint(static_cast<int>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else if (f < 0 || f > 127)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " <<static_cast<int>(f) << std::endl;
	if (f - static_cast<int>(f) == 0)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

void	printDouble(std::string input)
{
	std::stringstream ss(input);
	double d;
	
	ss >> d;
	if (isprint(static_cast<int>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else if (d < 0 || d > 127)
		std::cout << "char: Impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " <<static_cast<int>(d) << std::endl;
	if (d - static_cast<int>(d) == 0)
	{
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void	printPseudoLiteral(std::string input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}
