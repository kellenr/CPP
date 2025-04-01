/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:38:17 by kellen            #+#    #+#             */
/*   Updated: 2025/03/23 18:57:26 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _value;
		static const int _fractionalBits;

	public:
		Fixed();                         // Default constructor
		Fixed(const int n);              // New: From int
		Fixed(const float f);            // New: From float
		Fixed(const Fixed& other);       // Copy constructor
		Fixed& operator=(const Fixed& other); // Assignment
		~Fixed();                        // Destructor

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;       // New
		int toInt(void) const;           // New

		// Comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Increment / Decrement
		Fixed& operator++();       // prefix
		Fixed operator++(int);     // postfix
		Fixed& operator--();       // prefix
		Fixed operator--(int);     // postfix

		//static min/max functions
		static Fixed & min( Fixed & a, Fixed & b );
		static Fixed & max( Fixed & a, Fixed & b );
		static Fixed const & min( Fixed const & a, Fixed const & b );
		static Fixed const & max( Fixed const & a, Fixed const & b );
};

// Stream insertion overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif