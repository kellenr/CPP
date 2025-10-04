/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:58:59 by kellen            #+#    #+#             */
/*   Updated: 2025/10/04 19:40:36 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b1("Alice", 2);
//		std::cout << b1.getName() << ", bureaucrat grade " << b1.getGrade() << std::endl;
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << "After increment: " << b1 << std::endl;
		b1.incrementGrade(); // This should throw an exception
	} catch (Bureaucrat::BureaucratException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << "After decrement: " << b2 << std::endl;
		b2.decrementGrade(); // This should throw an exception
	} catch (const Bureaucrat::BureaucratException& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	return 0;
}