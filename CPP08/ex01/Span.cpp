/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:26:02 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:26:12 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span() : _maxSize(0) {
}

// Parametric constructor
Span::Span(unsigned int N) : _maxSize(N) {
}

// Copy constructor
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {
}

// Assignment operator
Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

// Destructor
Span::~Span() {
}

// Add a single number
void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize) {
		throw SpanFullException();
	}
	_numbers.push_back(number);
}

// Find shortest span (smallest difference between any two numbers)
int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw NoSpanException();
	}

	// Sort a copy of the vector
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	// The shortest span must be between adjacent elements in sorted array
	int minSpan = std::numeric_limits<int>::max();

	for (size_t i = 0; i < sorted.size() - 1; i++) {
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan) {
			minSpan = span;
		}
	}

	return minSpan;
}

// Find longest span (largest difference between any two numbers)
int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw NoSpanException();
	}

	// Find min and max elements
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}