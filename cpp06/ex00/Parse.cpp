/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Parse.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/27 12:13:00 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/01 17:22:37 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"
#include <sstream>

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

bool	isInt(std::string input)
{
	if (input.empty())
		return false;
	if (input[0] == '+' || input[0] == '-')
		if (input.length() == 1)
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
	int i_dot = 0;
	int i_f = 0;
	for (char ch : input)
	{
		if (ch == '.')
			if (++i_dot > 1)
				return false;
		if (ch == 'f')
			if (++i_f > 1)
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
	int i = std::stoi(input);
	if(i > INT_MAX || i < INT_MIN)
		std::cout << "char: Impossible" << std::endl;
	if (ft_isprint(static_cast<unsigned int>(i)))
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
	if (ft_isprint(static_cast<unsigned int>(c)))
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
	float f = std::stof(input);
	if(f > INT_MAX || f < INT_MIN)
		std::cout << "char: Impossible" << std::endl;
	if (ft_isprint(static_cast<unsigned int>(f)))
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
	double d = std::stod(input);
	if(d > INT_MAX || d < INT_MIN)
		std::cout << "char: Impossible" << std::endl;
	if (ft_isprint(static_cast<double>(d)))
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
