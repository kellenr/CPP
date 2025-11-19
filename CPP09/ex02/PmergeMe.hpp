/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:38:03 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:38:10 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

class PmergeMe {
private:
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;

	// Vector implementation
	void mergeInsertSortVector(std::vector<int>& arr);
	void insertionSortVector(std::vector<int>& arr, int left, int right);

	// Deque implementation
	void mergeInsertSortDeque(std::deque<int>& arr);
	void insertionSortDeque(std::deque<int>& arr, int left, int right);

	// Utility
	bool isValidNumber(const std::string& str) const;
	void displaySequence(const std::vector<int>& arr, const std::string& prefix) const;

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void parseInput(int argc, char** argv);
	void sort();
};

#endif