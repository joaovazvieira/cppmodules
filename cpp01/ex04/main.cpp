/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jovieira <jovieira@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/22 14:49:39 by jovieira      #+#    #+#                 */
/*   Updated: 2024/06/06 12:44:15 by jovieira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "usage: Sed <filename> <find> <replace>" << std::endl;
		return 1;
	}

	std::string	data;
	std::string buffer = std::string(argv[1]) + ".replace";
	std::ifstream	input_file(argv[1], std::ifstream::in);

	if (!input_file.good())
	{
		std::cerr << "Error: fail to open input file" << std::endl;
		return 1;
	}
	std::ofstream	output_file(buffer.c_str());
	if (!output_file.good())
	{
		std::cerr << "Error: fail to open output file" << std::endl;
		return 1;
	}
	while (input_file.good())
	{
		std::getline(input_file, buffer);
		data += buffer;
		if (!input_file.eof())
			data += "\n";
	}
	replace(data, argv[2], argv[3]);
	output_file << data;
	output_file.close();
	input_file.close();
}
