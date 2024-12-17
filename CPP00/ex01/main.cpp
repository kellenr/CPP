/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:34:03 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 21:06:45 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	phoneBook.display_info();
	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input == "ADD" || input == "1")
			phoneBook.add_contact();
		else if (input == "SEARCH" || input == "2")
			phoneBook.search_contact();
		else if (input == "EXIT" || input == "3")
		{
			system("clear");
			std::cout << "Goodbye! 👋🏻" << std::endl;
			return (0);
		}
		else
			std::cout << "Invalid command. Try again" << std::endl;
	}
	return (0);
}
