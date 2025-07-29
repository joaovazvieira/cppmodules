/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 14:52:00 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/29 21:20:01 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}

	try {
		Bitcoin bitcoin;
		std::map<std::string, double> rateDB = bitcoin.loadData("data.csv");
		if (rateDB.empty())
			return 1;
		bitcoin.init(argv[1], rateDB);
	} catch (std::exception &e) {
		return 1;
	}
	return 0;
}