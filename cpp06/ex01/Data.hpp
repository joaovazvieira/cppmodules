/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/03 14:42:36 by jovieira      #+#    #+#                 */
/*   Updated: 2025/04/14 13:59:05 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	private:
		std::string _name;
		int			_age;

	public:
		Data(std::string name, int age);
		Data(const Data& copy, int age);
		~Data();

		std::string const &getName() const;
		int getAge() const;
		Data &operator=(const Data& other);
};

	std::ostream &operator<<(std::ostream &src ,Data const &out);
#endif