/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 14:52:00 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/16 14:44:31 by jovieira      ########   odam.nl         */
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

	std::map<std::string, double> rateDB = loadData("Data.csv");
	std::ifstream inputFile(argv[1]);
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening input file." << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(inputFile, line))
	{
		if (line.empty()) continue;
		
		size_t pipe = line.find('|');
		if (pipe == std::string::npos)
		{
			std::cerr << "Bad input ==> " << line << std::endl;
			continue;
		}
		
		std::string date = line.substr(0, pipe);
		std::string valurStr = line.substr(pipe + 1);

		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
	}
}