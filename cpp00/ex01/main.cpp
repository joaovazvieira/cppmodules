/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/19 19:06:13 by jovieira      #+#    #+#                 */
/*   Updated: 2024/05/19 19:21:42 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
    Phonebook   book;
    std::string input;

    while (!std::cin.eof())
    {
        std::cout << "Enter a command: ADD | SEARCH | EXIT" << std::endl;
        std::getline(std::cin, input);
        if (input == "ADD")
            book.add();
        else if (input == "SEARCH")
            book.search();
        else if (input == "EXIT")
            return 0;
    }
    return 0;
}