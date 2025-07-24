/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 09:18:21 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/22 10:41:01 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./RPN \"expression\"" << std::endl;
		return 1;
	}
	
	RPN rpn;
	rpn.calc(argv[1]);
	return 0;
}