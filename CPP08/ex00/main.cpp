/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:23:32 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:23:33 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
	// Test with vector
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << "=== Testing with vector ===" << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		easyfind(vec, 10);
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test with list
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	std::cout << "\n=== Testing with list ===" << std::endl;
	try {
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	// Test with deque
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);

	std::cout << "\n=== Testing with deque ===" << std::endl;
	try {
		std::deque<int>::iterator it = easyfind(deq, 200);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}