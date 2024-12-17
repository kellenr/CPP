/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:33:08 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 21:51:43 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), total(0)
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::display_info()
{
	system("clear");
	std::cout << "+=============================================+" << std::endl;
	std::cout << "+          📞 MY AWESOME PHONEBOOK 📞         +" << std::endl;
	std::cout << "+=============================================+" << std::endl;
	std::cout << "+        Add a new contact.  - 1 / ADD        +" << std::endl;
	std::cout << "+        Search a contact.   - 2 / SEARCH     +" << std::endl;
	std::cout << "+        Exit the PhoneBook. - 3 / EXIT       +" << std::endl;
	std::cout << "+                                             +" << std::endl;
	std::cout << "+=============================================+" << std::endl;
}

void	PhoneBook::add_contact()
{
	std::string input, first_name, last_name, nickname, phone_number, darkest_secret;

	// Input validation loop
	while (first_name.empty()) {
		display_info();
		std::cout << "Enter First Name: ";
		std::getline(std::cin, first_name);
	}

	while (last_name.empty()) {
		display_info();
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, last_name);
	}

	while (nickname.empty()) {
		display_info();
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, nickname);
	}

	while (phone_number.empty()) {
		display_info();
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, phone_number);
	}

	while (darkest_secret.empty()) {
		display_info();
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, darkest_secret);
	}

	// Check for duplicate contacts
	for (int i = 0; i < total; i++) {
		if (contacts[i].get_first_name() == first_name &&
			contacts[i].get_last_name() == last_name &&
			contacts[i].get_phone_number() == phone_number) {
			std::cout << "Duplicate contact detected. Not added!" << std::endl;
			return;
		}
	}

	// Add the contact
	contacts[index].set_first_name(first_name);
	contacts[index].set_last_name(last_name);
	contacts[index].set_nickname(nickname);
	contacts[index].set_phone_number(phone_number);
	contacts[index].set_darkest_secret(darkest_secret);
	display_info();
	std::cout << "Contact added successfully!" << std::endl;

	index = (index + 1) % 8; // Replace the oldest contact if full
	if (total < 8)
		total++;
}

void	PhoneBook::search_contact()
{
	if (contacts[0].get_first_name().empty())
	{
		std::cout << "No contacts available." << std::endl;
		return ;
	}
	system("clear");
	std::cout << "+==============================================+" << std::endl;
	std::cout << "|               📋 CONTACT LIST 📋             |" << std::endl;
	std::cout << "+----------+----------+----------+-------------+" << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < total; i++) {
		contacts[i].displayShort(i + 1);
	}

	std::cout << "+==============================================+\n" << std::endl;
	std::string input;
	int index = -1;

	while (true) {
		std::cout << "Enter an index to view details (or -1 to cancel): ";
		std::getline(std::cin, input);

		if (input.empty() || input == "-1") {
			display_info();
			std::cout << "Search cancelled! Returning to main menu." << std::endl;
			return;
		}
		// Convert string to int using atoi
		index = std::atoi(input.c_str());

		if (input.empty() || index < 1 || index > total) {
			std::cout << "Invalid index. Try again!" << std::endl;
		} else {
			display_info();
			contacts[index - 1].displayFull();
			break;
		}
	}
}

