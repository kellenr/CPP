/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:58:59 by kellen            #+#    #+#             */
/*   Updated: 2025/10/04 20:21:08 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat b1("Alice", 50);
		Form f1("FormA", 10, 50);

		std::cout << b1 << std::endl;

		b1.signForm(f1); // This should throw an exception
		std::cout << f1 << std::endl;
	} catch (Form::FormException& e) {
		std::cerr << "Form Exception: " << e.what() << std::endl;
	}

	return 0;
}