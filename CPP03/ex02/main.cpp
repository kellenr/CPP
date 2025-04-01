/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:36:37 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:36:39 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap player1("SpongeBob");
	FragTrap player2("Patrik");
	FragTrap player3("Squidward");

	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	player1.attack("Squidward");
	player3.takeDamage(30);
	player3.beRepaired(30);
	player1.highFivesGuys();
	std::cout << std::endl;
	player2.attack("Squidward");
	player3.takeDamage(30);
	player3.beRepaired(30);
	player2.highFivesGuys();
	std::cout << std::endl;
	player3.attack("SpongeBob");
	player1.takeDamage(30);
	player1.beRepaired(30);
	player3.highFivesGuys();
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	return 0;
}
