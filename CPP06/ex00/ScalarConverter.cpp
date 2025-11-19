/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:20:13 by kellen            #+#    #+#             */
/*   Updated: 2025/11/12 20:08:11 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) { (void)other; return *this; }

ScalarConverter::~ScalarConverter(void) {}

/* --------------------------------------------------------------------------- */

void ScalarConverter::convert(std::string const &input)
{
	int i = std::atoi(input.c_str());

	std::cout << "char: ";
	if (input.size() == 1 && !std::isdigit(input[0]))
		i = static_cast<int>(input[0]);
	if (i == 0 && !(input.size() == 1 && input[0] == '0'))
		std::cout << "impossible" << std::endl;
	else if (std::isprint(i))
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (i == 0 && !(input.size() == 1 && input[0] == '0'))
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;

	std::cout << "float: ";
	char *end;
	float f = std::strtof(input.c_str(), &end);
	if (input.size() == 1 && !std::isdigit(input[0]))
	{
		f = static_cast<float>(input[0]);
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else if (end == input.c_str() || (f == 0.0f && input != "0" && input != "0.0"))
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;

	std::cout << "double: ";
	double d = std::strtod(input.c_str(), &end);
	if (input.size() == 1 && !std::isdigit(input[0]))
	{
		d = static_cast<double>(input[0]);
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else if (end == input.c_str() || (d == 0.0 && input != "0" && input != "0.0"))
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;

}