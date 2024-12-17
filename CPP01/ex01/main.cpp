/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:58:41 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 23:05:31 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	num = 5;
	std::string name = "HordeZombie";
	Zombie* horde = zombieHorde(num, name);
	if (horde)
	{
		for (int i = 0; i < num; i++) {
			horde[i].announce();
		}
		delete[] horde; // Clean up memory
	}

	std::cout << "\n--- End of Zombies---" << std::endl;
	return 0;

}
