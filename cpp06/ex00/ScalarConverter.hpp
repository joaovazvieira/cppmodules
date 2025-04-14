/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 16:07:00 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/10 15:34:51 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		
		ScalarConverter & operator=(ScalarConverter const &src);

	public:
		static void convert(std::string input);
};

#endif