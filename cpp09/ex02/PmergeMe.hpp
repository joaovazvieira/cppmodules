/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/23 12:21:37 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/24 11:47:27 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {

	private:
	
	template<typename Container>
	void sortInput(const Container &input, Container &large, Container &small);
	template<typename Container>
	void recursiveSort(Container &large); //, Container &small
	template<typename Container>
	void insertSmall(Container &sortedLarge, const Container &small);
	public:
		PmergeMe(); // Private constructor to prevent instantiation
		PmergeMe(const PmergeMe& other); // Copy constructor
		~PmergeMe(); // Destructor
		PmergeMe& operator=(const PmergeMe& other); // Assignment operator 
		
		void fordJohnsonSort(std::vector<int> &vec);
		void fordJohnsonSort(std::deque<int> &deq);
		
};

#endif