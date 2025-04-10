/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:00:26 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 21:00:38 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Animal.cpp
#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("Animal"){
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &other) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

std::string AAnimal::getType(void) const {
	return this-> type;
}