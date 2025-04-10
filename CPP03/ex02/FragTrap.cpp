/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:36:14 by kellen            #+#    #+#             */
/*   Updated: 2025/04/10 17:17:17 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FragTrap.cpp
#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

// Parameterized constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap parameterized constructor called for " << name << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

// Assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << getName() << std::endl;
}

// Special ability
void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << getName() << " requests a high five from everyone!" << std::endl;
}
