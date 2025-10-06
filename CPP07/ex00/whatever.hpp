/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:08:54 by kellen            #+#    #+#             */
/*   Updated: 2025/10/06 22:10:58 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template< typename T >
T &		min(T &a, T &b) {
	return (a < b ? a : b);
}

template< typename T >
T &		max(T &a, T &b) {
	return (a > b ? a : b);
}

#endif