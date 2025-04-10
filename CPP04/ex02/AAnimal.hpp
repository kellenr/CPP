/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:00:05 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 20:56:31 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Animal.hpp
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>


class AAnimal
{
	protected:
		std::string type;
		AAnimal(void);
		AAnimal(AAnimal const &other);

	public:
		virtual ~AAnimal(void);
		AAnimal &operator=(AAnimal const &other);
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif