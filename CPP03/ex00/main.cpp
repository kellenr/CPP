/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:34:43 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:34:46 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap("SpongeBob");
	ClapTrap claptrap2("Patrik");

	claptrap.setAttackDamage(5);
	claptrap2.setAttackDamage(3);

	while (claptrap.getEnergyPoints() > 0 && claptrap2.getEnergyPoints() > 0)
	{
		std::cout << "--------------------------------------------------------------------" << std::endl;
		std::cout << claptrap.getName() << " Energy points: " << claptrap.getEnergyPoints() << std::endl;
		std::cout << claptrap2.getName() << " Energy points: " << claptrap.getEnergyPoints() << std::endl;
		std::cout << "--------------------------------------------------------------------" << std::endl;
		claptrap.attack("Patrik");
		claptrap2.takeDamage(5);
		claptrap2.beRepaired(5);
		claptrap2.attack("SpongeBob");
		claptrap.takeDamage(3);
		claptrap.beRepaired(3);
		if(claptrap.getEnergyPoints() == 0)
			std::cout << claptrap.getName() << " is out of energy points!" << std::endl;
		if(claptrap2.getEnergyPoints() == 0)
			std::cout << claptrap2.getName() << " is out of energy points!" << std::endl;
	}

/* 	ClapTrap claptrap3;
	ClapTrap claptrap4(claptrap);

	claptrap3.setName("Sandy");

	claptrap3.setAttackDamage(3);
	claptrap4.setAttackDamage(7);

	claptrap3.attack("SpongeBob");
	claptrap4.takeDamage(3);
	claptrap4.beRepaired(3);

	claptrap4.attack("Sandy");
	claptrap3.takeDamage(7);
	claptrap3.beRepaired(7);
*/
	return 0;
}
