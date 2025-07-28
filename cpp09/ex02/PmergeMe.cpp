/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/23 13:56:48 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/28 17:40:06 by jovieira      ########   odam.nl         */
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
	std::cout << std::endl;
	for (size_t i = 0; i < newLarge.size(); ++i)
		std::cout << newLarge[i] << std::endl;
	recursiveSort(newLarge);
	for (const auto &elem : newSmall) {
		auto pos = std::lower_bound(newLarge.begin(), newLarge.end(), elem);
		newLarge.insert(pos, elem);
	}
	large = newLarge;
}

template<typename Container>
void PmergeMe::insertSmall(Container &sortedLarge, const Container &small) {
	// need to generate the index with jacobsthal
	// use index to insert from small to large
	std::vector<size_t> index;
	size_t j0 = 0, j1 = 1;
	if (small.size() > 0) index.push_back(j0);
	if (small.size() > 1) index.push_back(j1);
	for (size_t i = 2; ; ++i) {
		size_t jacobNumber = index[i - 1] + (2 * index[i - 2]);
		if (jacobNumber >= small.size())
			break;
		index.push_back(jacobNumber);
	}
	// for (size_t i = 0; i < index.size(); ++i)
	// 	std::cout << index[i] << std::endl;
	std::vector<bool> inserted(small.size(), false);

	for (size_t idx : index) {
		auto pos = std::lower_bound(sortedLarge.begin(), sortedLarge.end(), small[idx]);
		sortedLarge.insert(pos, small[idx]);
		inserted[idx] = true;
	}
	// for (size_t i = 0; i < small.size(); ++i)
	// 	std::cout << small[i] << std::endl;
	// for (size_t i = 0; i < sortedLarge.size(); ++i)
	// 	std::cout << sortedLarge[i] << std::endl;
	for (size_t i = 0; i< small.size(); ++i){
		if (!inserted[i]) {
			auto pos = std::lower_bound(sortedLarge.begin(), sortedLarge.end(), small[i]);
			sortedLarge.insert(pos, small[i]);
		}
	}
}

void PmergeMe::fordJohnsonSort(std::vector<size_t> &vec) {
	std::vector<size_t> large, small;
	sortInput(vec, large, small);
	recursiveSort(large);
	insertSmall(large, small);
	vec = std::move(large);
}

void PmergeMe::fordJohnsonSort(std::deque<size_t> &deq) {
	std::deque<size_t> large, small;
	sortInput(deq, large, small);
	recursiveSort(large);
	insertSmall(large, small);
	deq = std::move(large);
}