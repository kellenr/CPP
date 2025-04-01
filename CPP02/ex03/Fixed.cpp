/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:26:59 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:27:05 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* --------constructors/destructor------------- */

Fixed::Fixed( void ) : _fixedPointValue(0) {}

Fixed::Fixed( Fixed const & other ) { *this = other; }

Fixed::~Fixed( void ) {}

Fixed::Fixed( const int intValue ) {
	_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed( const float floatValue ) {
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

/* ----------Assignment operatos--------------- */
Fixed & Fixed::operator=( Fixed const & other ) {
	this->_fixedPointValue = other.getRawBits();
	return *this;
}

/* ---------Setters/Getters--------------------------*/
int Fixed::getRawBits( void ) const {
	return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
	this->_fixedPointValue = raw;
}

/* ----------Conversion functions------------------ */
float Fixed::toFloat( void ) const {
	return (float)_fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const {
	return _fixedPointValue >> _fractionalBits;
}

/* --------------------operators overload ------------------------------ */
std::ostream & operator<<(std::ostream & stream, Fixed const & other) {
	stream << other.toFloat();
	return stream;
}

// Comparison operators

bool Fixed::operator>(Fixed const & other) const {
	return _fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(Fixed const & other) const {
	return _fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(Fixed const & other) const {
	return _fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(Fixed const & other) const {
	return _fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(Fixed const & other) const {
	return _fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(Fixed const & other) const {
	return _fixedPointValue != other._fixedPointValue;
}

// Arithmetic operators
Fixed Fixed::operator+(Fixed const & other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const & other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const & other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const & other) const {
	if (other.toFloat() != 0)
		return Fixed(this->toFloat() / other.toFloat());
	else {
		std::cerr << "Invalid division by zero" << std::endl;
		exit(1);
	}
}

// (pre/post)Increment/Decrement operators
Fixed & Fixed::operator++() {
	_fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	operator++();
	return temp;
}

Fixed & Fixed::operator--() {
	_fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	operator--();
	return temp;
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