/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 12:27:06 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/07 13:29:07 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }

//default container deque
// int main() {
//     MutantStack<int> mstack;

//     std::cout << "Pushing elements: 5, 17, 3, 10" << std::endl;
//     mstack.push(5);
//     mstack.push(17);
//     mstack.push(3);
//     mstack.push(10);

// 	std::cout << "Stack size after pushing: " << mstack.size() << std::endl;
//     std::cout << "Top of stack: " << mstack.top() << std::endl;
// 	MutantStack<int>::iterator itt = mstack.begin();
//     MutantStack<int>::iterator itet = mstack.end();
//     int post = 0;
//     while (itt != itet) {
//         std::cout << "  [" << post++ << "] " << *itt << std::endl;
//         ++itt;
//     }

//     std::cout << "\nPopping the top (" << mstack.top() << ")" << std::endl;
//     mstack.pop();  // Removes 10
//     std::cout << "Stack size after pop: " << mstack.size() << std::endl;

//     std::cout << "\nIterating from bottom to top:" << std::endl;
//     // Since std::stack is LIFO, the beginning of the underlying container is the bottom of the stack.
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     int pos = 0;
//     while (it != ite) {
//         std::cout << "  [" << pos++ << "] " << *it << std::endl;
//         ++it;
//     }

//     std::cout << "\nIterating in reverse (top to bottom):" << std::endl;
//     for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
//         std::cout << "  - " << *rit << std::endl;
//     }

//     return 0;
// }

//changed container list
int main() {
    MutantStack<int> mstack;

    std::cout << "Pushing elements: 5, 17, 3, 10" << std::endl;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(10);

	std::cout << "Stack size after pushing: " << mstack.size() << std::endl;
    std::cout << "Top of stack: " << mstack.top() << std::endl;
	MutantStack<int>::iterator itt = mstack.begin();
    MutantStack<int>::iterator itet = mstack.end();
    int post = 0;
    while (itt != itet) {
        std::cout << "  [" << post++ << "] " << *itt << std::endl;
        ++itt;
    }

    std::cout << "\nPopping the top (" << mstack.top() << ")" << std::endl;
    mstack.pop();  // Removes 10
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;

    std::cout << "\nIterating from bottom to top:" << std::endl;
    // Since std::stack is LIFO, the beginning of the underlying container is the bottom of the stack.
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    int pos = 0;
    while (it != ite) {
        std::cout << "  [" << pos++ << "] " << *it << std::endl;
        ++it;
    }

    std::cout << "\nIterating from top to bottom (reverse):" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << "  - " << *rit << std::endl;
    }

    return 0;
}