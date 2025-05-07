/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 13:56:53 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/02 14:40:40 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _nSize(N) {}

void Span::addNumber(int number)
{
	if (_numbers.size() >=_nSize)
		throw std::runtime_error("Span is full: unable to add numbers");
	_numbers.push_back(number);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t rangeSize = std::distance(begin, end);
	if (_numbers.size() + rangeSize > _nSize)
		throw std::runtime_error("Range exceeds span capacity");
	_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Span non existent: shortest span");
	
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++)
	{	
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Span non existent: longest span");
	
	int minVal = *std::min_element(_numbers.begin(), _numbers.end());
	int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
	
	return maxVal - minVal;
}