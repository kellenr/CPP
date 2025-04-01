/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 19:04:03 by kellen            #+#    #+#             */
/*   Updated: 2025/04/01 10:29:38 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	Point a(0, 0);
	Point b(1, 0);
	Point c(0, 1);

	Point inside(0.5, 0.5);
	Point outside(1.5, 1.5);
	Point onEdge(0.5, 0);
	Point onVertex(0, 0);
	Point outsideButClose(1.01, 0.99);

	Point testPoints[] = {inside, outside, onEdge, onVertex, outsideButClose};

	std::string descriptions[] = {
		"inside the triangle",
		"outside the triangle",
		"on the edge of the triangle",
		"on a vertex of the triangle",
		"outside but close to the triangle"
	};

	for (int i = 0; i < 5; i++) {
		std::cout << "Testing point " << descriptions[i] << ": ";
		if (bsp(a, b, c, testPoints[i])) {
			std::cout << "Point is inside the triangle.\n";
		} else {
			std::cout << "Point is not inside the triangle.\n";
		}
	}
	return 0;
}