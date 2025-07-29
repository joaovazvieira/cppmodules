/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 14:52:28 by jovieira      #+#    #+#                 */
/*   Updated: 2025/07/29 22:00:02 by jovieira      ########   odam.nl         */
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
	Bitcoin(const Bitcoin &copy) = default;
	~Bitcoin();
	Bitcoin &operator=(const Bitcoin &src) = default;
	
	void init(const char *file, std::map<std::string, double> rateDB);
	bool isValidDate(const std::string &date);
	bool isValidValue(const std::string &str);
	std::map<std::string, double> loadData(const std::string &filename);
	bool getCloseRate(const std::map<std::string, double>& db, const std::string &date, double &rate);

	class BitcoinError : public std::exception {
		private:
			std::string msg;
		public:
			BitcoinError(const std::string &message) : msg(message) {}
			virtual const char* what() const noexcept override {
				return msg.c_str();
			}
	};
};

#endif