/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:30:31 by kellen            #+#    #+#             */
/*   Updated: 2025/03/23 18:31:36 by kellen           ###   ########.fr       */
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
};

// Stream insertion overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
