/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:26:28 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:26:37 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	// Test from subject
	std::cout << "=== Test from subject ===" << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test exceptions
	std::cout << "\n=== Test exceptions ===" << std::endl;
	{
		Span sp = Span(3);

		try {
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4); // This should throw
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

		try {
			Span empty = Span(5);
			empty.addNumber(42);
			empty.shortestSpan(); // This should throw
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	// Test with 10,000+ numbers
	std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
	{
		Span sp = Span(10000);

		srand(time(NULL));
		for (int i = 0; i < 10000; i++) {
			sp.addNumber(rand());
		}

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test addRange with iterators
	std::cout << "\n=== Test addRange ===" << std::endl;
	{
		Span sp = Span(100);

		std::vector<int> numbers;
		for (int i = 1; i <= 50; i++) {
			numbers.push_back(i * 2);
		}

		sp.addRange(numbers.begin(), numbers.end());

		std::cout << "After adding range:" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test with duplicates
	std::cout << "\n=== Test with duplicates ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(10);
		sp.addNumber(20);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	return 0;
}