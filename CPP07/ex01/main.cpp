/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:14:53 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:44:00 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1f, 2.2f, 3.3f};
	double doubleArray[] = {1.11, 2.22, 3.33, 4.44};
	char charArray[] = {'B', 'a', 'r', 'b', 'a', 'r', 'a'};
	std::string stringArray[] = {"Walter", "Barbara", "Blue", "Victor"};

	std::cout << "Integer Array:" << std::endl;
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "Float Array:" << std::endl;
	iter(floatArray, 3, printElement<float>);
	std::cout << std::endl;

	std::cout << "Double Array:" << std::endl;
	iter(doubleArray, 4, printElement<double>);
	std::cout << std::endl;

	std::cout << "Char Array:" << std::endl;
	iter(charArray, 7, printElement<char>);
	std::cout << std::endl;

	std::cout << "String Array:" << std::endl;
	iter(stringArray, 4, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}