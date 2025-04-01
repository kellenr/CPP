/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:28:21 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:28:24 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point {
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &other);
		~Point(void);

		Point &	operator=(Point const &other);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

	private:
		Fixed	_x;
		Fixed	_y;
};

#endif