/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:11:08 by kellen            #+#    #+#             */
/*   Updated: 2025/11/13 17:39:44 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main (void ) {
	// ===== INT =====
	int a = 2;
	int b = 3;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	// ===== FLOAT =====
	float f1 = 1.5f;
	float f2 = 3.7f;

	std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
	::swap(f1, f2);
	std::cout << "After swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min( f1, f2 ) = " << ::min(f1, f2) << std::endl;
	std::cout << "max( f1, f2 ) = " << ::max(f1, f2) << std::endl;
	std::cout << std::endl;

	// ===== DOUBLE =====
	double d1 = 42.42;
	double d2 = 10.01;

	std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;
	::swap(d1, d2);
	std::cout << "After swap: d1 = " << d1 << ", d2 = " << d2 << std::endl;
	std::cout << "min( d1, d2 ) = " << ::min(d1, d2) << std::endl;
	std::cout << "max( d1, d2 ) = " << ::max(d1, d2) << std::endl;
	std::cout << std::endl;

	// ===== CHAR =====
	char c1 = 'a';
	char c2 = 'z';

	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	::swap(c1, c2);
	std::cout << "After swap: c1 = " << c1 << ", c2 = " << c2 << std::endl;
	std::cout << "min( c1, c2 ) = " << ::min(c1, c2) << std::endl;
	std::cout << "max( c1, c2 ) = " << ::max(c1, c2) << std::endl;
	std::cout << std::endl;

	// ===== STRING =====
	std::string s1 = "Kellen1";
	std::string s2 = "kellen2";

	std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	::swap(s1, s2);
	std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
	std::cout << "min( s1, s2 ) = " << ::min(s1, s2) << std::endl;
	std::cout << "max( s1, s2 ) = " << ::max(s1, s2) << std::endl;
	std::cout << std::endl;

	return 0;
}