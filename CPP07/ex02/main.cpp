/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:21:46 by kellen            #+#    #+#             */
/*   Updated: 2025/11/13 17:35:08 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
	// try {
	// 	Array<int> intArray(5);
	// 	for (unsigned int i = 0; i < intArray.size(); ++i) {
	// 		intArray[i] = i * 10;
	// 	}
	// 	std::cout << "Integer Array:" << std::endl;
	// 	for (unsigned int i = 0; i < intArray.size(); ++i) {
	// 		std::cout << intArray[i] << std::endl;
	// 	}

	// 	Array<std::string> stringArray(3);
	// 	stringArray[0] = "Hello";
	// 	stringArray[1] = "World";
	// 	stringArray[2] = "42 School";
	// 	std::cout << "\nString Array:" << std::endl;
	// 	for (unsigned int i = 0; i < stringArray.size(); ++i) {
	// 		std::cout << stringArray[i] << std::endl;
	// 	}

	// 	// Testing out-of-bounds access
	// 	std::cout << "\nAttempting out-of-bounds access:" << std::endl;
	// 	std::cout << intArray[10] << std::endl; // This should throw an exception
	// } catch (const Array<int>::OutOfBoundException &e) {
	// 	std::cerr << "Exception: " << e.what() << std::endl;
	// } catch (const Array<std::string>::OutOfBoundException &e) {
	// 	std::cerr << "Exception: " << e.what() << std::endl;
	// } catch (const std::exception &e) {
	// 	std::cerr << "General Exception: " << e.what() << std::endl;
	// }

	// return 0;

	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;

}