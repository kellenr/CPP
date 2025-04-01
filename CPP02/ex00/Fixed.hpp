/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:07:12 by kellen            #+#    #+#             */
/*   Updated: 2025/03/23 18:31:23 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int _value;                         // Fixed-point value
		static const int _fractionalBits;   // Number of fractional bits (always 8)

	public:
		Fixed();                            // Default constructor
		Fixed(const Fixed& other);          // Copy constructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator
		~Fixed();                           // Destructor

		int getRawBits(void) const;         // Get raw fixed-point value
		void setRawBits(int const raw);     // Set raw fixed-point value
};

#endif