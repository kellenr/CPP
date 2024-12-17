/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:16:00 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 23:32:25 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {
	private:
		std::string type;

	public:
		Weapon(std::string type);
		~Weapon();

		const std::string& getType() const; // Returns a const reference to type
		void setType(const std::string& newType); // Sets a new type
};

#endif
