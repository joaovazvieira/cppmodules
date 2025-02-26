/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 16:07:00 by jovieira      #+#    #+#                 */
/*   Updated: 2025/02/26 16:14:53 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER.HPP
#define SCALARCONVERTER.HPP

#include <string>
#include <iostream>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		
		ScalarConverter & operator=(ScalarConverter const &src);
		
		static void convert(std::string input);
};

#endif