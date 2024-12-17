/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:33:02 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 21:53:40 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

std::string Contact::get_first_name() const {return first_name;}
std::string Contact::get_last_name() const {return last_name;}
std::string Contact::get_nickname() const {return nickname;}
std::string Contact::get_phone_number() const {return phone_number;}
std::string Contact::get_darkest_secret() const {return darkest_secret;}

void Contact::set_first_name(const std::string &value) {first_name = value;}
void Contact::set_last_name(const std::string &value) {last_name = value;}
void Contact::set_nickname(const std::string &value) {nickname = value;}
void Contact::set_phone_number(const std::string &value) {phone_number = value;}
void Contact::set_darkest_secret(const std::string &value) {darkest_secret = value;}

std::string	get_truncated(std::string str)
{
	if (str.size() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

void Contact::displayShort(int index) const {
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << get_truncated(first_name) << "|";
	std::cout << std::setw(10) << get_truncated(last_name) << "|";
	std::cout << std::setw(10) << get_truncated(nickname) << std::endl;
}

void Contact::displayFull() const {
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
	std::cout << "+==============================================+\n" << std::endl;
}
