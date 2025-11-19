/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:28:37 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:28:46 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	// Orthodox Canonical Form
	MutantStack() : std::stack<T>() {}

	MutantStack(const MutantStack& other) : std::stack<T>(other) {}

	MutantStack& operator=(const MutantStack& other) {
		if (this != &other) {
			std::stack<T>::operator=(other);
		}
		return *this;
	}

	~MutantStack() {}

	// Iterator typedefs
	// std::stack uses std::deque by default as underlying container
	// We access it through the protected member 'c'
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	// Iterator functions
	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}

	const_iterator begin() const {
		return this->c.begin();
	}

	const_iterator end() const {
		return this->c.end();
	}

	reverse_iterator rbegin() {
		return this->c.rbegin();
	}

	reverse_iterator rend() {
		return this->c.rend();
	}

	const_reverse_iterator rbegin() const {
		return this->c.rbegin();
	}

	const_reverse_iterator rend() const {
		return this->c.rend();
	}
};

#endif