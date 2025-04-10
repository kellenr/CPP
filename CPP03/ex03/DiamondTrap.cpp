/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:37:41 by kellen            #+#    #+#             */
/*   Updated: 2025/04/10 17:19:24 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DiamondTrap.cpp
#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	name = "Default";
	setHitPoints(FragTrap::getHitPoints());     // 100 from FragTrap
	setEnergyPoints(ScavTrap::getEnergyPoints()); // 50 from ScavTrap
	setAttackDamage(FragTrap::getAttackDamage()); // 30 from FragTrap
}

// Parameterized constructor
DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap parameterized constructor called for " << name << std::endl;
	this->name = name;
	setHitPoints(FragTrap::getHitPoints());     // 100 from FragTrap
	setEnergyPoints(ScavTrap::getEnergyPoints()); // 50 from ScavTrap
	setAttackDamage(FragTrap::getAttackDamage()); // 30 from FragTrap
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		name = other.name;
	}
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

// Special ability
void DiamondTrap::whoAmI() {
	std::cout << "I am DiamondTrap " << name << " and my ClapTrap name is "
			<< ClapTrap::getName() << std::endl;
}

// Override attack to use ScavTrap's version
void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}
