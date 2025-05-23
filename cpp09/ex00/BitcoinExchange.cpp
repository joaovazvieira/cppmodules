/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/14 13:44:41 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/16 12:56:50 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool Bitcoin::isValidDate(const std::string &date)
{
	if (date.size() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	int year, month, day;
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	} catch (std::exception &e) {
		return false;
	}
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	return true;
}

bool Bitcoin::isValidValue(const std::string &str, float &value)
{
	try {
		value = std::stof(str);
		if (value < 0 || value > 1000)
			return false;
	} catch (std::exception &e){
		return false;
	}
	return true;
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
	
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date, priceStr;
		if (std::getline(ss, date, ',') && std::getline(ss, priceStr)){
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
double Bitcoin::getCloseRate(const std::map<std::string, double>& db, const std::string &date, double &rate)
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
