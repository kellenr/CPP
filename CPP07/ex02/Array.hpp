/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:20:22 by kellen            #+#    #+#             */
/*   Updated: 2025/11/13 17:33:25 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>

#define MAX_VAL 750


template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &other);
		~Array(void);

		Array &operator=(Array const &other);
		T &operator[](unsigned int index);

		unsigned int size(void) const;

		class OutOfBoundException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		T *_array;
		unsigned int _size;
};

template <typename T>
Array<T>::Array(void): _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n): _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array const &other): _array(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>::~Array(void)
{
	if (this->_array)
		delete[] this->_array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this->_array)
		delete[] this->_array;
	this->_array = new T[other._size];
	this->_size = other._size;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = other._array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw Array<T>::OutOfBoundException();
	return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
const char *Array<T>::OutOfBoundException::what() const throw()
{
	return ("Array index out of bounds!");
}

#endif
