/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:00:06 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 20:10:29 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//WrongAnimal.hpp
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(WrongAnimal const &other);
		~WrongAnimal(void);

		std::string getType(void) const;
		void makeSound(void) const;
};

#endif