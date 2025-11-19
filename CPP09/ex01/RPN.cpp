/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:37:07 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:37:14 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN& other) : _stack(other._stack) {
}

RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {
}

bool RPN::isOperator(const std::string& token) const {
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::performOperation(int a, int b, char op) const {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0) {
				throw std::runtime_error("Error: division by zero");
			}
			return a / b;
		default:
			throw std::runtime_error("Error: invalid operator");
	}
}

int RPN::calculate(const std::string& expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (isOperator(token)) {
			if (_stack.size() < 2) {
				throw std::runtime_error("Error");
			}

			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();

			int result = performOperation(a, b, token[0]);
			_stack.push(result);
		}
		else {
			// Check if token is a valid number (single digit)
			if (token.length() != 1 || !isdigit(token[0])) {
				throw std::runtime_error("Error");
			}

			int num = token[0] - '0';
			_stack.push(num);
		}
	}

	if (_stack.size() != 1) {
		throw std::runtime_error("Error");
	}

	return _stack.top();
}