/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:58:59 by kellen            #+#    #+#             */
/*   Updated: 2025/10/04 22:40:17 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main()
{
	std::cout << "🌳 ShrubberyCreationForm — Multi-Bureaucrat Test 🌳" << std::endl;

	Bureaucrat alice("Alice", 1);        // can do anything
	Bureaucrat bob("Bob", 137);          // just enough to execute Shrubbery
	Bureaucrat charlie("Charlie", 150);  // too weak

	// Each gets their own target name (so the files will differ)
	ShrubberyCreationForm garden1("AliceGarden");
	ShrubberyCreationForm garden2("BobGarden");
	ShrubberyCreationForm garden3("CharlieGarden");

	std::cout << "\n--- Alice signs & executes her form ---" << std::endl;
	try {
		alice.signForm(garden1);
		alice.executeForm(garden1);
	} catch (const std::exception& e) {
		std::cerr << "❌ Alice error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Bob signs & executes his form ---" << std::endl;
	try {
		bob.signForm(garden2);
		bob.executeForm(garden2);
	} catch (const std::exception& e) {
		std::cerr << "❌ Bob error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Charlie tries (should fail) ---" << std::endl;
	try {
		charlie.signForm(garden3);
		charlie.executeForm(garden3);
	} catch (const std::exception& e) {
		std::cerr << "❌ Charlie error: " << e.what() << std::endl;
	}

	return 0;
}