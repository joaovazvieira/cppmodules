/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 13:38:11 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/02 13:56:16 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <limits>
#include <vector>

class Span
{
	private:
		unsigned int _nSize;
		std::vector<int> _numbers;
	
	public:
		Span(unsigned int N);
		void addNumber(int number);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		int shortestSpan();
		int longestSpan();
};

#endif