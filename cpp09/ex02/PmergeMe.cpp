/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/23 13:56:48 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/24 11:47:54 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void)other;
	// Copy constructor logic (if needed)
}
PmergeMe::~PmergeMe() {
	// Destructor logic (if needed)
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other; // Suppress unused parameter warning
	return *this;
}

template<typename Container>
void PmergeMe::sortInput(const Container &input, Container &large, Container &small) {
	large.clear();
	small.clear();
	for (size_t i = 0; i + 1 < input.size(); i += 2){
		if (input[i] > input[i + 1]){
			large.push_back(input[i]);
			small.push_back(input[i + 1]);
		} else {
			large.push_back(input[i + 1]);
			small.push_back(input[i]);
		}
	}
	if (input.size() % 2) { //ford-johnson put the unpaired elements in the larg container
		large.push_back(input.back());
	}
}

// , Container &small
template<typename Container>
void PmergeMe::recursiveSort(Container &large) {
	if (large.size() <= 1) {
		return; // Base case: already sorted
	}
	
	Container newLarge, newSmall;
	sortInput(large, newLarge, newSmall);
	// std::cout << "inside recursive sort" << std::endl;
	// for (const int& val : large) {
    // std::cout << val << " ";
	// }
	std::cout << std::endl;
	recursiveSort(newLarge);

	for (const auto &elem : newSmall) {
		auto pos = std::lower_bound(newLarge.begin(), newLarge.end(), elem);
		newLarge.insert(pos, elem);
	}
	// for (size_t i = 0; i < newSmall.size(); ++i) {
	// 	auto pos = std::lower_bound(newLarge.begin(), newLarge.end(), newSmall[i]);
	// 	newLarge.insert(pos, newSmall[i]);
	// }
	
	// for (size_t i = 0; i < small.size(); ++i) {
	// 	auto pos = std::lower_bound(newLarge.begin(), newLarge.end(), small[i]);
	// 	newLarge.insert(pos, small[i]);
	// }
	large = newLarge;
}

template<typename Container>
void PmergeMe::insertSmall(Container &sortedLarge, const Container &small) {
	for (const auto &elem : small) {
		auto pos = std::lower_bound(sortedLarge.begin(), sortedLarge.end(), elem);
		sortedLarge.insert(pos, elem);
	}
}

void PmergeMe::fordJohnsonSort(std::vector<int> &vec) {
	std::vector<int> large, small;
	// std::cout << "inside ford johnson before" << std::endl;
	// for (const int& val : vec) {
    // std::cout << val << " ";
	// }
	// std::cout << std::endl;
	sortInput(vec, large, small);
	// std::cout << "inside ford johnson after" << std::endl;
	// for (const int& val : vec) {
    // std::cout << val << " ";
	// }
	// std::cout << std::endl;
	recursiveSort(large);
	insertSmall(large, small);
	// std::cout << "inside ford johnson sorted" << std::endl;
	// for (const int& val : large) {
    // std::cout << val << " ";
	// }
	// std::cout << std::endl;
	vec = std::move(large);
}

void PmergeMe::fordJohnsonSort(std::deque<int> &deq) {
	std::deque<int> large, small;
	sortInput(deq, large, small);
	recursiveSort(large);
	insertSmall(large, small);
	deq = std::move(large);
}