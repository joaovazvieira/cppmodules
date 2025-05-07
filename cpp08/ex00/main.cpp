/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/01 14:34:25 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/02 13:34:35 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> container;
	for (int i = -5; i < 15; i++)
		container.push_back(i);
	try
	{
		std::vector<int>::iterator it = easyfind(container, -2);
		std::cout << "Found " << *it << std::endl;
		easyfind(container, 100);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << '\n';

	std::deque<int> contdeque;
	for (int i = 0; i < 15; i++)
		contdeque.push_back(i);
	try
	{
		std::deque<int>::iterator it = easyfind(contdeque, 2);
		std::cout << "Found " << *it << std::endl;
		easyfind(contdeque, 100);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << '\n';

	std::list<int> contlist;
	for (int i = 0; i < 15; i++)
		contlist.push_back(i);
	try
	{
		std::list<int>::iterator it = easyfind(contlist, 10);
		std::cout << "Found " << *it << std::endl;
		easyfind(contlist, 100);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}