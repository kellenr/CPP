/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:58:34 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 23:01:18 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0) {
		std::cerr << "Invalid number of zombies!" << std::endl;
		return NULL;
	}

	Zombie* horde = new Zombie[N]; // Allocate a block of Zombies

	for (int i = 0; i < N; i++) {
		horde[i].setName(name); // Set the name for each Zombie
	}

	return horde;
}
