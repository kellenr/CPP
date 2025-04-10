/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:37:41 by kellen            #+#    #+#             */
/*   Updated: 2025/04/10 17:19:58 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Updated main.cpp for ex03
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	std::cout << "--- Testing ClapTrap ---" << std::endl;
	ClapTrap clap("CL4P-TP");
	clap.attack("Target Dummy");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n--- Testing ScavTrap ---" << std::endl;
	ScavTrap scav("SC4V-TP");
	scav.attack("Enemy Robot");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "\n--- Testing FragTrap ---" << std::endl;
	FragTrap frag("FR4G-TP");
	frag.attack("Boss Enemy");
	frag.takeDamage(50);
	frag.beRepaired(30);
	frag.highFivesGuys();

	std::cout << "\n--- Testing DiamondTrap ---" << std::endl;
	DiamondTrap diamond("D14M-TP");
	diamond.attack("Super Boss"); // Should use ScavTrap's attack
	diamond.takeDamage(40);
	diamond.beRepaired(25);
	diamond.guardGate();      // ScavTrap ability
	diamond.highFivesGuys();  // FragTrap ability
	diamond.whoAmI();         // DiamondTrap's special ability

	std::cout << "\n--- Testing Construction/Destruction Order ---" << std::endl;
	{
		std::cout << "Creating a DiamondTrap..." << std::endl;
		DiamondTrap temp("Temporary");
		std::cout << "DiamondTrap created, now going out of scope..." << std::endl;
	}

	return 0;
}
