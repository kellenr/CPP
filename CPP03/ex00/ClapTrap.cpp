/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:34:15 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:34:19 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitpoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitpoints(10), _energyPoints(10), _attackDamage(0) {
	_name = name;
	std::cout << "Constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "Copy Constructor called." << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called." << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Assignation operator called." << std::endl;
	if (this == &other)
		return *this;
	_name = other._name;
	_hitpoints = other._hitpoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

void ClapTrap::attack(std::string const &target)
{
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
	<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitpoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount
	<< " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	_hitpoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " is repaired and gains " << amount
	<< " points!" << std::endl;
}

void ClapTrap::setAttackDamage(int damage)
{
	_attackDamage = damage;
}

void ClapTrap::setName(std::string name)
{
	_name = name;
}

int ClapTrap::getHitpoints(void) const
{
	return _hitpoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

std::string ClapTrap::getName(void) const
{
	return _name;
}
