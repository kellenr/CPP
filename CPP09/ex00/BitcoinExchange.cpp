/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:35:52 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:36:02 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <limits>

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFile) {
	loadDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_database = other._database;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

std::string BitcoinExchange::trim(const std::string& str) const {
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

float BitcoinExchange::stringToFloat(const std::string& str) const {
	std::stringstream ss(str);
	float result;
	ss >> result;
	return result;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 2009 || year > 2023)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	// Simple day validation
	if (month == 2) {
		bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (day > (leap ? 29 : 28))
			return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	return true;
}

bool BitcoinExchange::isValidValue(float value) const {
	return value >= 0 && value <= 1000;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // Skip header

	while (std::getline(file, line)) {
		size_t comma = line.find(',');
		if (comma == std::string::npos)
			continue;

		std::string date = trim(line.substr(0, comma));
		std::string valueStr = trim(line.substr(comma + 1));

		if (!isValidDate(date))
			continue;

		float rate = stringToFloat(valueStr);
		_database[date] = rate;
	}

	file.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
	// Try to find exact date
	std::map<std::string, float>::const_iterator it = _database.find(date);
	if (it != _database.end()) {
		return it->second;
	}

	// Find closest lower date
	it = _database.lower_bound(date);
	if (it == _database.begin()) {
		return 0; // No earlier date exists
	}

	--it; // Get the previous (lower) date
	return it->second;
}

void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // Skip header

	while (std::getline(file, line)) {
		size_t pipe = line.find('|');
		if (pipe == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string dateStr = trim(line.substr(0, pipe));
		std::string valueStr = trim(line.substr(pipe + 1));

		// Validate date
		if (!isValidDate(dateStr)) {
			std::cerr << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		// Validate value
		float value = stringToFloat(valueStr);

		// Check for negative
		if (valueStr[0] == '-' || value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		// Check for too large
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		// Get exchange rate and calculate
		float rate = getExchangeRate(dateStr);
		float result = value * rate;

		std::cout << dateStr << " => " << value << " = " << result << std::endl;
	}

	file.close();
}