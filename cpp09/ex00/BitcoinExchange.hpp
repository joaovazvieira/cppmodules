/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 14:52:28 by jovieira      #+#    #+#                 */
/*   Updated: 2025/05/16 12:58:39 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <regex>
#include <map>
#include <cctype>


class Bitcoin
{
	private:

	public:
	Bitcoin();
	~Bitcoin();
	
	bool isValidDate(const std::string &date);
	bool isValidValue(const std::string &str, float &value);
	std::map<std::string, double> loadData(const std::string &filename);
	double getCloseRate(const std::map<std::string, double>& db, const std::string &date, double &rate);
	
};

#endif