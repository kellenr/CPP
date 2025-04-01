/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:39:57 by kellen            #+#    #+#             */
/*   Updated: 2025/03/23 18:59:53 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

// Constructors and destructor
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n) {
	_value = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
	_value = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) { *this = other; }

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		_value = other._value;
	return *this;
}

Fixed::~Fixed() {}

// Getters / Setters
int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

// Conversion
float Fixed::toFloat(void) const {
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
	return _value > other._value;
}
bool Fixed::operator<(const Fixed& other) const {
	return _value < other._value;
}
bool Fixed::operator>=(const Fixed& other) const {
	return _value >= other._value;
}
bool Fixed::operator<=(const Fixed& other) const {
	return _value <= other._value;
}
bool Fixed::operator==(const Fixed& other) const {
	return _value == other._value;
}
bool Fixed::operator!=(const Fixed& other) const {
	return _value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed& other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

// Increment / Decrement
Fixed& Fixed::operator++() {
	_value++;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_value++;
	return temp;
}
Fixed& Fixed::operator--() {
	_value--;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_value--;
	return temp;
}

// Output stream overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

// Static member functions
Fixed & Fixed::min(Fixed & a, Fixed & b) {
	return (a < b) ? a : b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b) {
	return (a < b) ? a : b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b) {
	return (a > b) ? a : b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b) {
	return (a > b) ? a : b;
}
