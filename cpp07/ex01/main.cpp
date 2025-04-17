/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/17 16:25:55 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/17 16:35:08 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int array[] = {1, 2, 3, 4, 5};
	std::string strArr[] = {"Chesse", "Tomato", "Dough"};

	std::cout << "printing int array -> " << "\n";
	iter(array, 5, printElement);

	std::cout << "printing pizza array -> " << "\n";
	iter(strArr, 3, printElement);

	return 0;
}