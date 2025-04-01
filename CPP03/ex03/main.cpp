/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:37:41 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:38:42 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap player1("Diamond");
	std::cout << std::endl;
	ScavTrap player2("Scav");
	std::cout << std::endl;
	FragTrap player3("Frag");
	std::cout << std::endl;
	ClapTrap player4("Clap");

	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	player1.whoAmI();
	std::cout << "Hit Points: " << player1.getHitPoints() <<  " Attack Damage: " << player1.getAttackDamage()
	<< " Energy Points: " << player1.getEnergyPoints() << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << player2.getName() << std::endl;
	std::cout << "Hit Points: " << player2.getHitPoints() <<  " Attack Damage: " << player2.getAttackDamage()
	<< " Energy Points: " << player2.getEnergyPoints() << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << player3.getName() << std::endl;
	std::cout << "Hit Points: " << player3.getHitPoints() <<  " Attack Damage: " << player3.getAttackDamage()
	<< " Energy Points: " << player3.getEnergyPoints() << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << player4.getName() << std::endl;
	std::cout << "Hit Points: " << player4.getHitPoints() <<  " Attack Damage: " << player4.getAttackDamage()
	<< " Energy Points: " << player4.getEnergyPoints() << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;


	std::cout << "---------------------Functions inheritance test---------------------" << std::endl;
	player1.attack("Frag");
	player1.guardGate();
	player1.highFivesGuys();
	std::cout << std::endl;

	return 0;
}
