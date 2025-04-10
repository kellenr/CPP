/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:00:12 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 20:13:04 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//WrongCat.hpp
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat( WrongCat const & other );
		WrongCat & operator=( WrongCat const & other );
		~WrongCat( void );

		void	makeSound( void ) const;
};

#endif