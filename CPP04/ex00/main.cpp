/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:00:58 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 20:19:09 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "----- Testing Animal, Dog, Cat -----" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "Animal Type: " << j->getType() << std::endl;
	std::cout << "Other Type: " << i->getType() << std::endl;
	std::cout << "Meta" << meta->getType() << std::endl;

	std::cout << "\nMaking sounds:" << std::endl;
	i->makeSound(); // Will output the cat sound
	j->makeSound(); // Will output the dog sound
	meta->makeSound(); // Will output the animal sound

	std::cout << "\n----- Testing WrongAnimal, WrongCat -----" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "WrongCat Type: " << wrongCat->getType() << std::endl;
	std::cout << "WrongMeta Type: " << wrongMeta->getType() << std::endl;

	std::cout << "\nMaking wrong sounds:" << std::endl;
	wrongCat->makeSound(); // Will output WrongAnimal sound, not WrongCat sound
	wrongMeta->makeSound();

	std::cout << "\n----- Cleaning up -----" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongCat;

	return 0;
}

/*
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	...
	return 0;
}
*/