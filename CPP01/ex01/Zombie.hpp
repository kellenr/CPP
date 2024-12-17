/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:57:48 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 23:03:04 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string name;

	public:
		Zombie();                 // Default constructor
		Zombie(std::string name); // Constructor with name
		~Zombie();                // Destructor

		void setName(std::string name); // Setter for name
		void announce() const;          // Makes the zombie speak
};

Zombie* zombieHorde(int N, std::string name);

#endif

