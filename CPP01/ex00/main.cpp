/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:26:46 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 22:53:11 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::cout << "\n--- Creating Zombies on the Heap ---" << std::endl;
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie; // Cleanup heap memory

	std::cout << "\n--- Creating Zombies on the Stack ---" << std::endl;
	randomChump("StackZombie");

	std::cout << "\n--- End of Zombies ---" << std::endl;
	return 0;
}
