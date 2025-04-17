/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/17 17:38:59 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/17 18:20:57 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <cstdlib>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[5] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

#include <iostream>
#include "Array.hpp"  // include your class template

int main() {
    std::cout << "🟢 Testing default constructor..." << std::endl;
    Array<int> emptyArray;
    std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

    std::cout << "\n🟢 Testing constructor with size..." << std::endl;
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 10;  // fill the array with values
    }

    std::cout << "Values in intArray: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\n🟢 Testing copy constructor..." << std::endl;
    Array<int> copyArray(intArray);  // make a copy
    copyArray[0] = 999;  // modify the copy

    std::cout << "Original intArray[0]: " << intArray[0] << std::endl;
    std::cout << "Copied copyArray[0]: " << copyArray[0] << std::endl;

    std::cout << "\n🟢 Testing assignment operator..." << std::endl;
    Array<int> assignArray;
    assignArray = intArray;  // test assignment
    assignArray[1] = 888;

    std::cout << "Original intArray[1]: " << intArray[1] << std::endl;
    std::cout << "Assigned assignArray[1]: " << assignArray[1] << std::endl;

    std::cout << "\n🟢 Testing out-of-bounds access..." << std::endl;
    try {
        std::cout << intArray[10] << std::endl;  // invalid index!
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n🟢 Testing with std::string..." << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "world";
    strArray[2] = "!";

    for (unsigned int i = 0; i < strArray.size(); ++i) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
