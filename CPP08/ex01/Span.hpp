/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:25:03 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:25:40 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <limits>

class Span {
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	// Orthodox Canonical Form
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	// Member functions
	void addNumber(int number);

	// Add range of numbers using iterators
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		while (begin != end) {
			if (_numbers.size() >= _maxSize) {
				throw SpanFullException();
			}
			_numbers.push_back(*begin);
			++begin;
		}
	}

	int shortestSpan() const;
	int longestSpan() const;

	// Exceptions
	class SpanFullException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Span is full, cannot add more numbers";
		}
	};

	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Not enough numbers to calculate span";
		}
	};
};

#endif