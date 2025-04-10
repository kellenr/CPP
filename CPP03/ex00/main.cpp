/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:34:43 by kellen            #+#    #+#             */
/*   Updated: 2025/04/10 16:58:45 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "ClapTrap.hpp"

int main() {
	ClapTrap clap1("CL4P-TP");
	ClapTrap clap2("FR4G-TP");

	clap1.setAttackDamage(3);
	clap2.setAttackDamage(3);

	while(clap1.getEnergyPoints() > 0 && clap2.getEnergyPoints() > 0)
	{
		std::cout << "--------------------------------------------------------------------" << std::endl;
		std::cout << clap1.getName() << " Energy points: " << clap1.getEnergyPoints() << std::endl;
		std::cout << clap2.getName() << " Energy points: " << clap2.getEnergyPoints() << std::endl;
		std::cout << "--------------------------------------------------------------------" << std::endl;
		clap1.attack("Target Dummy");
		clap1.attack("Enemy");
		clap1.takeDamage(5);
		clap1.beRepaired(4);
		clap2.attack("Enemy");
		clap1.takeDamage(6);
		clap1.beRepaired(4);
		clap1.attack("Target Dummy");
		clap2.attack("Target Dummy");
	}
	return 0;
}
