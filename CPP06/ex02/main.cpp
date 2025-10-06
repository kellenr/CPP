/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:00:12 by kellen            #+#    #+#             */
/*   Updated: 2025/10/06 22:05:04 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <exception>

static Base *generate(void) {
	int random = rand() % 3;

	if (random == 0) {
		std::cout << "Generated A" << std::endl;
		return (new A());
	}
	else if (random == 1) {
		std::cout << "Generated B" << std::endl;
		return (new B());
	}
	else {
		std::cout << "Generated C" << std::endl;
		return (new C());
	}
}

static void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified type: C" << std::endl;
	else
		std::cout << "Type could not be identified" << std::endl;
}

static void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "By reference: A" << std::endl;
	}
	catch (...) {}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "By reference: B" << std::endl;
	}
	catch (...) {}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "By reference: C" << std::endl;
	}
	catch (...) {}
}

int main(void) {
	srand(time(NULL));

	Base *base = generate();

	identify(base);
	identify(*base);

	delete base;

	return (0);
}
