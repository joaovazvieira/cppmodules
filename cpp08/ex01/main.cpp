/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:20:37 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/02 14:40:14 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    try {
        Span sp(5);
        sp.addNumber(10);
        sp.addNumber(1);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Test with many numbers
        Span bigSpan(1000000000);
        std::vector<int> bulk;
        for (int i = 0; i < 1000000; ++i)
            bulk.push_back(i);
        bigSpan.addRange(bulk.begin(), bulk.end());

        std::cout << "Shortest Span : " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span : " << bigSpan.longestSpan() << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}