/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:35:26 by kellen            #+#    #+#             */
/*   Updated: 2025/04/10 17:15:07 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Updated main.cpp for ex01
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	std::cout << "\n--- Testing Construction/Destruction Order ---" << std::endl;
	{
		std::cout << "Creating a ScavTrap..." << std::endl;
		ScavTrap temp("Temporary");
		std::cout << "ScavTrap created, now going out of scope..." << std::endl;
	}

	return 0;
}

