/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:28:40 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:28:42 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

//Barycentric coordinates method

static Fixed calculateArea(Point const& p1, Point const& p2, Point const& p3) {
	return (p1.getY() - p2.getY()) * (p3.getX() - p2.getX()) + (p2.getX() - p1.getX()) * (p3.getY() - p2.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed triangle = calculateArea(a, b, c);

	Fixed A = calculateArea(point, b, c) / triangle;
	Fixed B = calculateArea(a, point, c) / triangle;
	Fixed C = calculateArea(a, b, point) / triangle;

	return A >= Fixed(0) && B >= Fixed(0) && C >= Fixed(0);
}