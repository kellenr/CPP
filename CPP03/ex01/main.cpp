/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:35:26 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:35:29 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap player2("Patrik");
	ScavTrap player1("SpongeBob");
	ScavTrap player3("Squidward");

	player2.setAttackDamage(30);

	player3.guardGate();

	while (player1.getEnergyPoints() > 0 && player2.getEnergyPoints() > 0 && player3.getEnergyPoints() > 0)
	{
		std::cout << "--------------------------------------------------------------------" << std::endl;
		std::cout << player1.getName() << " Energy points: " << player1.getEnergyPoints() << std::endl;
		std::cout << player2.getName() << " Energy points: " << player2.getEnergyPoints() << std::endl;
		std::cout << player3.getName() << " Energy points: " << player3.getEnergyPoints() << std::endl;
		std::cout << "--------------------------------------------------------------------" << std::endl;
		player1.attack("Squidward");
		player3.takeDamage(20);
		player3.beRepaired(20);
		player2.attack("Squidward");
		player3.takeDamage(30);
		player3.beRepaired(30);
		player3.attack("SpongeBob");
		player1.takeDamage(20);
		player1.beRepaired(20);
		if(player1.getEnergyPoints() == 0)
			std::cout << player1.getName() << " is out of energy points!" << std::endl;
		if(player2.getEnergyPoints() == 0)
			std::cout << player2.getName() << " is out of energy points!" << std::endl;
		if(player3.getEnergyPoints() == 0)
			std::cout << player3.getName() << " is out of energy points!" << std::endl;
	}
	return 0;
}
