/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Parse.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/27 12:09:58 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/02 11:25:53 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARING_HPP
#define PARING_HPP

#include <iostream>
#include <limits.h>
#include <float.h>

bool	isInt(std::string input);
bool	isChar(std::string input);
bool	isFloat(std::string input);
bool	isDouble(std::string input);
bool	isPseudoLiteral(std::string input);

void	printInt(std::string input);
void	printChar(std::string input);
void	printFloat(std::string input);
void	printDouble(std::string input);
void	printPseudoLiteral(std::string input);

#endif