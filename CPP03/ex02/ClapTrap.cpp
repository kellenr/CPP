/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:35:57 by kellen            #+#    #+#             */
/*   Updated: 2025/04/10 17:16:40 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ClapTrap.cpp
#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap parameterized constructor called for " << name << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

// Assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other) {
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called for " << name << std::endl;
}

// Member functions
void ClapTrap::attack(const std::string& target) {
	if (energyPoints == 0 || hitPoints == 0) {
		std::cout << "ClapTrap " << name << " can't attack because it has no energy or hit points left!" << std::endl;
		return;
	}

	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
			<< attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= amount) {
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes " << amount << " damage and is destroyed!" << std::endl;
	} else {
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " damage! Hit points left: " << hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints == 0 || hitPoints == 0) {
		std::cout << "ClapTrap " << name << " can't repair because it has no energy or hit points left!" << std::endl;
		return;
	}

	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount
			<< " hit points! Current hit points: " << hitPoints << std::endl;
	energyPoints--;
}

// Getters
std::string ClapTrap::getName() const {
	return name;
}

unsigned int ClapTrap::getHitPoints() const {
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return attackDamage;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->attackDamage = attackDamage;
}
