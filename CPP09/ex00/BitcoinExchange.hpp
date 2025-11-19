/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:35:31 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:35:38 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
private:
	std::map<std::string, float> _database;

	bool isValidDate(const std::string& date) const;
	bool isValidValue(float value) const;
	float stringToFloat(const std::string& str) const;
	std::string trim(const std::string& str) const;

public:
	BitcoinExchange();
	BitcoinExchange(const std::string& databaseFile);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadDatabase(const std::string& filename);
	void processInput(const std::string& filename);
	float getExchangeRate(const std::string& date) const;
};

#endif