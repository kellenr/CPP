/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:42:10 by kellen            #+#    #+#             */
/*   Updated: 2025/10/06 21:47:31 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;

	data.i = 42;
	data.j = 84;

	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Original Data values: i = " << data.i << ", j = " << data.j << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << deserializedData << std::endl;
	std::cout << "Deserialized Data values: i = " << deserializedData->i << ", j = " << deserializedData->j << std::endl;

	return 0;
}

/* int main(void)
{
	Data *ptr = new Data;

	ptr->x = 2;
	ptr->y = 5;

	std::cout << "Adress of ptr: "<< ptr << std::endl;
	uintptr_t a = Serializer::serialize(ptr);
	std::cout << "Value of a: " << a << std::endl;
	Data *b = Serializer::deserialize(a);
	std::cout << "Value of b: " << b << std::endl;

	std::cout << "b->x = " << b->x << std::endl;
	std::cout << "b->y = " << b->y << std::endl;

	delete ptr;
} */