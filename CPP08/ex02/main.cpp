/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:29:19 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:29:28 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	std::cout << "=== Test from subject with MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "Iterating through MutantStack:" << std::endl;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int> s(mstack);
	}

	std::cout << "\n=== Same test with std::list (for comparison) ===" << std::endl;
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << "Back: " << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "Iterating through list:" << std::endl;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "\n=== Additional tests ===" << std::endl;
	{
		MutantStack<int> mstack;

		// Add numbers
		for (int i = 0; i < 10; i++) {
			mstack.push(i);
		}

		std::cout << "Forward iteration:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Reverse iteration:" << std::endl;
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Top: " << mstack.top() << std::endl;
	}

	std::cout << "\n=== Test with strings ===" << std::endl;
	{
		MutantStack<std::string> mstack;

		mstack.push("Hello");
		mstack.push("World");
		mstack.push("42");
		mstack.push("School");

		std::cout << "String stack contents:" << std::endl;
		for (MutantStack<std::string>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << std::endl;
		}
	}

	std::cout << "\n=== Test copy constructor ===" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(10);
		mstack.push(20);
		mstack.push(30);

		MutantStack<int> copy(mstack);

		std::cout << "Original stack:" << std::endl;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Copied stack:" << std::endl;
		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test assignment operator ===" << std::endl;
	{
		MutantStack<int> mstack1;
		mstack1.push(1);
		mstack1.push(2);

		MutantStack<int> mstack2;
		mstack2.push(100);

		mstack2 = mstack1;

		std::cout << "After assignment:" << std::endl;
		for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}