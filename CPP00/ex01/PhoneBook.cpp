/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:33:08 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/07 22:45:14 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
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
	std::cout << "+================ MY PHONEBOOK ☎️  ============+" << std::endl;
	std::cout << "+                                             +" << std::endl;
	std::cout << "+           ADD ✏️  - Add a new contact.       +" << std::endl;
	std::cout << "+        SEARCH 🔎 - Search a contact.        +" << std::endl;
	std::cout << "+            EXIT  - Exit the PhoneBook.      +" << std::endl;
	std::cout << "+                                             +" << std::endl;
	std::cout << "+=============================================+" << std::endl;
}

void	PhoneBook::add_contact()
{
	Contact		contact;
	std::string	input;
	int			i;

	i = this->index % this->max;
	std::cout << "First name: ";
	std::getline(std::cin, input);
	contact.set_first_name(input);

	std::cout << "Last name: ";
	std::getline(std::cin, input);
	contact.set_last_name(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	contact.set_nickname(input);

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	contact.set_phone_number(input);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	contact.set_darkest_secret(input);

	this->contacts[i] = contact;
	std::cout << "Contact added." << std::endl;
	this->index++;
}

void	PhoneBook::search_contact()
{
	if (contacts[0].get_first_name().empty())
	{
		std::cout << "No contacts available." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First name" << "|"
	<< std::setw(10) << "Last name" << "|" << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < max; i++)
	{
		if (!contacts[i].get_first_name().empty())
		{
			std::cout << std::setw(10) << i << "|" << std::setw(10)
			<< contacts[i].get_first_name() << "|" << std::setw(10)
			<< contacts[i].get_last_name() << "|" << std::setw(10)
			<< contacts[i].get_nickname() << std::endl;
		}
	}
	while (1)
	{
		int	i;
		std::cout << "Enter an index: " << std::endl;
		std::cin >> i;
		if (std::cin.eof() || i < 0 || i >= index || i >= max)
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			if (index >= max)
				std::cout << "Invalid index. Try again." << std::endl;
			else
				std::cout << "Contact not found." << std::endl;
		}
		else
		{
			std::cout << "First name: " << contacts[i].get_first_name() << std::endl;
			std::cout << "Last name: " << contacts[i].get_last_name() << std::endl;
			std::cout << "Nickname: " << contacts[i].get_nickname() << std::endl;
			std::cout << "Phone number: " << contacts[i].get_phone_number() << std::endl;
			std::cout << "Darkest secret: " << contacts[i].get_darkest_secret() << std::endl;
			std::cout << "+=============================================+" << std::endl;
			std::cin.ignore(256, '\n');
			return ;
		}
	}
}

