/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 13:44:41 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/29 22:09:01 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::~Bitcoin() {}

bool Bitcoin::isValidDate(const std::string &date)
{
	std::stringstream ss(date);
	int year, month, day;
	char garbage;
	if (date.size() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;
	
	ss >> year >> garbage >> month >> garbage >> day;
	if (ss.fail() || !ss.eof())
		return false;
	if (year < 2009 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Check for leap year and adjust February
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeapYear && month == 2) {
		daysInMonth[1] = 29;
	}

	// Validate day against the correct number of days in the month
	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

bool Bitcoin::isValidValue(const std::string &str)
{
	std::stringstream ss(str);
	float value;
	try {
		ss >> value;
		if (ss.fail() || !ss.eof())
			throw BitcoinError("Error: unvalid value");
		if (value < 0)
			throw BitcoinError("Error: not a positive number.");
		else if (value >= 1000)
			throw BitcoinError("Error: too large a number.");
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
		return false;
	}
	return true;
}

bool compareNumber(std::string &priceStr, double def) {
	std::stringstream ss(priceStr);
	double price;
	ss >> price;
	return price < def;
}

std::map<std::string, double> Bitcoin::loadData(const std::string &filename)
{
	std::map<std::string, double> db;
	std::ifstream file(filename);
	std::string line;

	if (!file.is_open()){
		std::cerr << "Error opening database file." << std::endl;
		return db;
	}
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, priceStr;
		if (std::getline(ss, date, ',') && std::getline(ss, priceStr)){
			try{
				if (!isValidDate(date) || compareNumber(priceStr, 0)) {
					throw BitcoinError("Invalid Database entry");
				}
			} catch (std::exception &e) {
				std::cerr << e.what() << std::endl;
				db.clear();
				return db;
			}
			try{
				double price = std::stod(priceStr);
				db[date] = price;
			} catch (std::exception &e){
				continue;
			}
		}
	}
	return db;
}

bool Bitcoin::getCloseRate(const std::map<std::string, double>& db, const std::string &date, double &rate)
{
	auto it = db.lower_bound(date);
	if (it != db.end() && it->first == date)
	{
		rate = it->second;
		return true;
	} else if (it != db.begin()) 
	{
		--it;
		rate = it->second;
		return true;
	}
	return false;
}

void Bitcoin::init(const char *inputFile, std::map<std::string, double> rateDB) {
	std::ifstream file(inputFile);
	std::string line;
	
	if (!file.is_open())
		throw BitcoinError("Error opening input file.");
	std::getline(file, line);
	while (std::getline(file, line)) {
		try {
			if (line.empty()) continue;
			
			size_t pipe = line.find('|');
			if (pipe == std::string::npos) {
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}
			std::string date = line.substr(0, pipe);
			std::string valueStr = line.substr(pipe + 1);

			date.erase(0, date.find_first_not_of(" \t"));
			date.erase(date.find_last_not_of(" \t") + 1);
			valueStr.erase(0, valueStr.find_first_not_of(" \t"));
			valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

			if (!isValidDate(date)) {
				throw BitcoinError("Bad Date => " + date);
			}
			
			if (!isValidValue(valueStr)) {
				continue;
			}
			
			float value = std::stof(valueStr);
			double rate;
			if (getCloseRate(rateDB, date, rate)) {
				double result = value * rate;
				std::cout << date << " => " << value << " = " << result << std::endl;
			} else {
				std::cerr << "Error: bad input => "<< date << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}