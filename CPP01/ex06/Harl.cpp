/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 00:25:09 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/18 00:38:59 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {
	std::cout << "DEBUG:\nI love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void) {
	std::cout << "INFO:\nI cannot believe adding extra bacon costs more money.\n"
	<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void) {
	std::cout << "WARNING:\nI think I deserve to have some extra bacon for free.\n"
	<< "I’ve been coming here for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void) {
	std::cout << "ERROR:\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level) {
	// Array of function pointers and corresponding levels
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	// Match the level and call the corresponding function
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "UNKNOWN:\nLevel \"" << level << "\" is not recognized.\n" << std::endl;
}

// New: Filtered complaint handling
void Harl::filterComplaints(std::string level) {
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int startIndex = -1;
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			startIndex = i;
			break;
		}
	}

	if (startIndex == -1) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}

	for (int i = startIndex; i < 4; i++) {
		(this->*functions[i])();
	}
}
