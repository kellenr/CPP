/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:36:37 by kellen            #+#    #+#             */
/*   Updated: 2025/04/10 17:17:29 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Updated main.cpp for ex02
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

		std::cout << "\n--- Testing Construction/Destruction Order ---" << std::endl;
		{
			std::cout << "Creating a FragTrap..." << std::endl;
			FragTrap temp("Temporary");
			std::cout << "FragTrap created, now going out of scope..." << std::endl;
		}

		return 0;
}
