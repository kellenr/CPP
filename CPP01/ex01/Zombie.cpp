/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:58:37 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 23:00:29 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default Constructor
Zombie::Zombie() : name("") {}

// Constructor with name
Zombie::Zombie(std::string name) : name(name) {}

// Destructor
Zombie::~Zombie() {
	std::cout << "Zombie " << name << " destroyed." << std::endl;
}

// Setter for name
void Zombie::setName(std::string name) {
	this->name = name;
}

// Announce
void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
