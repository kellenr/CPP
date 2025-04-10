/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:00:58 by keramos-          #+#    #+#             */
/*   Updated: 2025/04/10 21:00:22 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=========================Subject's test=============================" << std::endl;
	const int size = 10;
	AAnimal* animals[size];

	for (int i = 0; i < size / 2; ++i)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; ++i)
		animals[i] = new Cat();
	for(int i = 0; i < size; i++)
	{
		std::cout << "Animal[" << i << "]: " << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	for(int i = 0; i < size; i++)
		delete animals[i];


	std::cout << "============================My tests===============================" << std::endl;
	std::cout << "----------------Dog tests--------------------" << std::endl;
	// Create a Dog object
	Dog dog1;
	std::cout << std::endl;
	dog1.makeSound();
	dog1.getBrain()->setIdea(0, "Chase the ball");
	std::cout << "Dog 1's idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	// Create another Dog object using copy constructor
	Dog dog2 = dog1;
	std::cout << std::endl;
	dog2.makeSound();
	std::cout << "Dog2's idea: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	// Modify the original dog's idea to ensure deep copy
	dog1.getBrain()->setIdea(0, "Chew the bone");
	std::cout << "Dog1's idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog2's idea after modifying Dog1: " << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << "-----------------Cat tests-------------------" << std::endl;

	// Create a Cat object
	Cat cat1;
	std::cout << std::endl;
	cat1.makeSound();
	cat1.getBrain()->setIdea(0, "Climb the tree");
	std::cout << "Cat 1's idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	// Create another Cat object using copy constructor
	Cat cat2 = cat1;
	std::cout << std::endl;
	cat2.makeSound();
	std::cout << "Cat2's idea: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	// Modify the original cat's idea to ensure deep copy
	cat1.getBrain()->setIdea(0, "Scratch the furniture");
	std::cout << "Cat1's idea: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2's idea after modifying Cat1: " << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	return 0;
}