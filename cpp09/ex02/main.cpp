/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/23 16:05:58 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/28 17:06:54 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <chrono>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: PmergeMe <list of elements>" << std::endl;
		return 1;
	}

	std::vector<size_t> vec;
	std::deque<size_t> deq;
	
	
	for (int i = 1; i < argc; ++i) {
		int val = std::stoi(argv[i]);
		// std::cout << val << " ";
		// if (*end != '\0' || end == argv[i]) {
		// 	std::cerr << "Invalid input: " << argv[i] << std::endl;
		// 	return 1;
		// }
		vec.push_back(static_cast<int>(val));
		deq.push_back(static_cast<int>(val));
	}
	
	std::cout << "\n";
	
	std::cout << "Unsorted elements: ";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << (i + 1 < argc ? " " : "");
	std::cout << std::endl;

	std::cout << "\n";

	// auto startVec = std::chrono::high_resolution_clock::now();
	PmergeMe().fordJohnsonSort(vec);
	// auto endVec = std::chrono::high_resolution_clock::now();
	
	std::cout << "Sorted vector: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << (i + 1 < vec.size() ? " " : "");
	std::cout << std::endl;
	
	std::cout << "\n";
	
	// auto startDeq = std::chrono::high_resolution_clock::now();
	PmergeMe().fordJohnsonSort(deq);
	// auto endDeq = std::chrono::high_resolution_clock::now();

	std::cout << "Sorted Deque: ";
	for (size_t i = 0; i < deq.size(); ++i)
		std::cout << deq[i] << (i + 1 < deq.size() ? " " : "");
	std::cout << std::endl;

	// auto timeVec = std::chrono::duration<double, std::micro>(endVec - startVec).count();
    // auto timeDeq = std::chrono::duration<double, std::micro>(endDeq - startDeq).count();

	std::cout << "\n";
	
    // std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << timeVec << " us" << std::endl;
    // std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << timeDeq << " us" << std::endl;

	return 1;
}