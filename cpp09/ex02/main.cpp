/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/23 16:05:58 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/30 10:48:34 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <chrono>
#include <sstream>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: PmergeMe <list of elements>" << std::endl;
		return 1;
	}

	std::vector<size_t> vec;
	std::deque<size_t> deq;
	
	
	for (int i = 1; i < argc; ++i) {
		std::string arg = argv[i];
		
		if (arg.empty()) {
			std::cerr << "Error: Empty argument" << std::endl;
			return 1;
		}
		//checks for any non digit character
		for (char c : arg) {
			if (!std::isdigit(c)){
				std::cerr << "Error: Invalid character " << std::endl;
				return 1 ;
			}
		}
		//looks for any number that would start with 0
		if (arg.length() > 1 && arg[0] == '0') {
			std::cerr << "Error: Leading zeros not allowed" << std::endl;
			return 1;
		}
		
		try {
			std::istringstream iss(arg);
			unsigned int val;
			iss >> val;
			vec.push_back(static_cast<unsigned int>(val));
			deq.push_back(static_cast<unsigned int>(val));
		} catch (const std::exception &e) {
			// std::cerr << "Error: Invalid number" << std::endl;
			return 1;
		}
	
	}
	std::cout << "\n";
	
	std::cout << "Unsorted elements: ";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << (i + 1 < argc ? " " : "");
	std::cout << std::endl;

	std::cout << "\n";

	auto startVec = std::chrono::high_resolution_clock::now();
	PmergeMe().fordJohnsonSort(vec);
	auto endVec = std::chrono::high_resolution_clock::now();
	
	std::cout << "Sorted vector: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << (i + 1 < vec.size() ? " " : "");
	std::cout << std::endl;
	
	std::cout << "\n";
	
	auto startDeq = std::chrono::high_resolution_clock::now();
	PmergeMe().fordJohnsonSort(deq);
	auto endDeq = std::chrono::high_resolution_clock::now();

	std::cout << "Sorted Deque: ";
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << deq[i] << (i + 1 < deq.size() ? " " : "");
	std::cout << std::endl;

	auto timeVec = std::chrono::duration<double, std::micro>(endVec - startVec).count();
    auto timeDeq = std::chrono::duration<double, std::micro>(endDeq - startDeq).count();

	std::cout << "\n";
	
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << timeDeq << " us" << std::endl;

	if (std::is_sorted(vec.begin(), vec.end()))
		std::cout << "Vector is sorted" << std::endl;
	else
		std::cout << "Vector not sorted" << std::endl;
	if (std::is_sorted(deq.begin(), deq.end()))
		std::cout << "Deque is sorted" << std::endl;
	else
		std::cout << "Deque not sorted" << std::endl;
	return 1;
}