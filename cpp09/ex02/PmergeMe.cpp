/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/23 13:56:48 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/29 08:44:17 by jovieira      ########   odam.nl         */
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
	recursiveSort(newLarge);
	for (const auto &elem : newSmall) {
		auto pos = std::lower_bound(newLarge.begin(), newLarge.end(), elem);
		newLarge.insert(pos, elem);
	}
	large = newLarge;
}

template<typename Container>
void PmergeMe::insertSmall(Container &sortedLarge, const Container &small) {
	if (small.empty()) return;
	
	std::vector<bool> inserted(small.size(), false);
	
	// Insert first element
	if (small.size() > 0) {
		auto pos = std::lower_bound(sortedLarge.begin(), sortedLarge.end(), small[0]);
		sortedLarge.insert(pos, small[0]);
		inserted[0] = true;
	}
	
	// Generate Jacobsthal sequence: 0, 1, 1, 3, 5, 11, 21, 43, ...
	std::vector<size_t> jacobsthal = {1};
	while (jacobsthal.back() < small.size()) {
		size_t next = jacobsthal.back() + 2 * (jacobsthal.size() > 1 ? jacobsthal[jacobsthal.size() - 2] : 0);
		if (next > small.size()) break;
		jacobsthal.push_back(next);
	}
	
	// Insert according to Jacobsthal sequence
	size_t lastIndex = 1;
	for (size_t j = 1; j < jacobsthal.size(); ++j) {
		size_t currentJacob = jacobsthal[j];
		if (currentJacob > small.size()) currentJacob = small.size();
		
		// Insert elements from currentJacob-1 down to lastIndex
		for (size_t i = currentJacob - 1; i >= lastIndex && i < small.size(); --i) {
			if (!inserted[i]) {
				auto pos = std::lower_bound(sortedLarge.begin(), sortedLarge.end(), small[i]);
				sortedLarge.insert(pos, small[i]);
				inserted[i] = true;
			}
		}
		lastIndex = currentJacob;
	}
	
	// Insert any remaining elements
	for (size_t i = 0; i < small.size(); ++i) {
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