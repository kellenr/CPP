/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:33:02 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/07 20:10:32 by keramos-         ###   ########.fr       */
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
