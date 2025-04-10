/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:36:52 by kellen            #+#    #+#             */
/*   Updated: 2025/04/10 17:17:40 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ScavTrap.cpp
#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap parameterized constructor called for " << name << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << getName() << std::endl;
}

// Specialized attack function
void ScavTrap::attack(const std::string& target) {
	if (getEnergyPoints() == 0 || getHitPoints() == 0) {
		std::cout << "ScavTrap " << getName() << " can't attack because it has no energy or hit points left!" << std::endl;
		return;
	}

	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing "
			<< getAttackDamage() << " points of damage!" << std::endl;
	// Decrease energy point
}

// Special ability
void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}
