/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:30:42 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/18 00:04:18 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2) : file(filename), sf1(s1), sf2(s2)
{
	if (sf1.empty() || sf2.empty())
	{
		std::cerr << "Error: Empty string" << std::endl;
		exit(1);
	}

	inputFile.open(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: Cannot open file: " << filename << std::endl;
		exit(1);
	}

	outputFile.open((filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Cannot create output file: " << filename << ".replace" << std::endl;
		inputFile.close();
		exit(1);
	}
}

Replace::~Replace(void)
{
	inputFile.close();
	outputFile.close();
}

void	Replace::replaceInFile(void)
{
	std::string line;
	while (std::getline(inputFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(sf1, pos)) != std::string::npos) {
			line.erase(pos, sf1.length());
			line.insert(pos, sf2);
			pos += sf2.length();
		}
		outputFile << line << std::endl;
	}
}
