/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:00:09 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 20:14:23 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const &other )
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=( WrongCat const &other )
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat makes Meow Meow" << std::endl;
}