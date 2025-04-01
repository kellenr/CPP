/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:34:31 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:34:33 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & other);
		~ClapTrap();

		ClapTrap & operator=(ClapTrap const & other);

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int getHitpoints(void) const;
		int getEnergyPoints(void) const;
		std::string getName(void) const;

		void setAttackDamage(int damage);
		void setName(std::string name);

	private:
		std::string _name;
		int _hitpoints;
		int _energyPoints;
		int _attackDamage;
};

#endif
