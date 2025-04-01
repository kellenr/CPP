/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:37:30 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:37:33 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	_name = name;
	std::cout << "ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy Constructor called." << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignation operator called." << std::endl;
	if (this == &other)
		return *this;
	_name = other.getName();
	_hitPoints = other.getHitPoints();
	_energyPoints = other.getEnergyPoints();
	_attackDamage = other.getAttackDamage();
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
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount
	<< " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	_hitPoints += amount;
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

int ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}

std::string ClapTrap::getName(void) const
{
	return _name;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	_energyPoints = energyPoints;
}
