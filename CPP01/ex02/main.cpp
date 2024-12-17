/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keramos- <keramos-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:07:57 by keramos-          #+#    #+#             */
/*   Updated: 2024/12/17 23:10:07 by keramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	// Step 1: Declare a string variable
	std::string brain = "HI THIS IS BRAIN";

	// Step 2: Create a pointer and a reference to the string
	std::string* stringPTR = &brain;   // Pointer to the string
	std::string& stringREF = brain;    // Reference to the string

	// Step 3: Print the memory addresses
	std::cout << "\n--- Memory Addresses ---" << std::endl;
	std::cout << "Address of string variable: " << &brain << std::endl;
	std::cout << "Address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "Address held by stringREF:  " << &stringREF << std::endl;

	// Step 4: Print the values
	std::cout << "\n--- Values ---" << std::endl;
	std::cout << "Value of string variable:   " << brain << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value referred to by stringREF: " << stringREF << std::endl;

	return 0;
}
