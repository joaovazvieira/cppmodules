/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 14:52:00 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/15 22:47:23 by jovieira      ########   odam.nl         */
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

	Bitcoin bitcoin;
	std::map<std::string, double> rateDB = bitcoin.loadData("data.csv");
	if (rateDB.empty())
		return 1;
	 std::ifstream inputFile(argv[1]);
	// if (!inputFile.is_open())
	// {
	// 	std::cerr << "Error opening input file." << std::endl;
	// 	return 1;
	// }
	std::string line;
	std::getline(inputFile, line); // Skip header line
	while (std::getline(inputFile, line))
	{
		try{
			if (line.empty()) continue;
			
			size_t pipe = line.find('|');
			if (pipe == std::string::npos)
			{
				std::cerr << "Bad input ==> " << line << std::endl;
				continue;
			}
			
			std::string date = line.substr(0, pipe);
			std::string valueStr = line.substr(pipe + 1);
			
			date.erase(0, date.find_first_not_of(" \t"));
			date.erase(date.find_last_not_of(" \t") + 1);
			
			if (!bitcoin.isValidDate(date))
				throw Bitcoin::BitcoinError("Bad Date ==> ");
			if (!bitcoin.isValidValue(valueStr))
				continue;
			std::cout << line << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << line << std::endl;
		}
	}
}