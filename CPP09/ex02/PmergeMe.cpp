/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:38:20 by kellen            #+#    #+#             */
/*   Updated: 2025/11/19 22:38:28 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe& other)
	: _vectorData(other._vectorData), _dequeData(other._dequeData) {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vectorData = other._vectorData;
		_dequeData = other._dequeData;
	}
	return *this;
}

PmergeMe::~PmergeMe() {
}

bool PmergeMe::isValidNumber(const std::string& str) const {
	if (str.empty())
		return false;

	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i]))
			return false;
	}

	long num = atol(str.c_str());
	return num >= 0 && num <= 2147483647;
}

void PmergeMe::parseInput(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		if (!isValidNumber(argv[i])) {
			throw std::runtime_error("Error");
		}

		int num = atoi(argv[i]);
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}

	if (_vectorData.empty()) {
		throw std::runtime_error("Error");
	}
}

void PmergeMe::displaySequence(const std::vector<int>& arr, const std::string& prefix) const {
	std::cout << prefix;

	size_t maxDisplay = 5;
	for (size_t i = 0; i < arr.size() && i < maxDisplay; i++) {
		std::cout << arr[i];
		if (i < arr.size() - 1)
			std::cout << " ";
	}

	if (arr.size() > maxDisplay) {
		std::cout << " [...]";
	}

	std::cout << std::endl;
}

// Simple insertion sort for small subarrays
void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr) {
	int n = arr.size();

	if (n <= 1)
		return;

	// For simplicity, use insertion sort for small arrays
	if (n < 20) {
		insertionSortVector(arr, 0, n - 1);
		return;
	}

	// Pair elements and sort pairs
	std::vector<std::pair<int, int> > pairs;
	int i;
	for (i = 0; i + 1 < n; i += 2) {
		if (arr[i] > arr[i + 1]) {
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		} else {
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		}
	}

	// Handle odd element
	int straggler = -1;
	bool hasStraggler = false;
	if (i < n) {
		straggler = arr[i];
		hasStraggler = true;
	}

	// Sort pairs by their larger element
	for (size_t j = 0; j < pairs.size(); j++) {
		for (size_t k = j + 1; k < pairs.size(); k++) {
			if (pairs[j].second > pairs[k].second) {
				std::swap(pairs[j], pairs[k]);
			}
		}
	}

	// Build main chain (larger elements)
	std::vector<int> mainChain;
	for (size_t j = 0; j < pairs.size(); j++) {
		mainChain.push_back(pairs[j].second);
	}

	// Insert smaller elements using binary insertion
	for (size_t j = 0; j < pairs.size(); j++) {
		int toInsert = pairs[j].first;
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), toInsert);
		mainChain.insert(pos, toInsert);
	}

	// Insert straggler if exists
	if (hasStraggler) {
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	arr = mainChain;
}

void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr) {
	int n = arr.size();

	if (n <= 1)
		return;

	if (n < 20) {
		insertionSortDeque(arr, 0, n - 1);
		return;
	}

	std::vector<std::pair<int, int> > pairs;
	int i;
	for (i = 0; i + 1 < n; i += 2) {
		if (arr[i] > arr[i + 1]) {
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
		} else {
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		}
	}

	int straggler = -1;
	bool hasStraggler = false;
	if (i < n) {
		straggler = arr[i];
		hasStraggler = true;
	}

	for (size_t j = 0; j < pairs.size(); j++) {
		for (size_t k = j + 1; k < pairs.size(); k++) {
			if (pairs[j].second > pairs[k].second) {
				std::swap(pairs[j], pairs[k]);
			}
		}
	}

	std::deque<int> mainChain;
	for (size_t j = 0; j < pairs.size(); j++) {
		mainChain.push_back(pairs[j].second);
	}

	for (size_t j = 0; j < pairs.size(); j++) {
		int toInsert = pairs[j].first;
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), toInsert);
		mainChain.insert(pos, toInsert);
	}

	if (hasStraggler) {
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(pos, straggler);
	}

	arr = mainChain;
}

void PmergeMe::sort() {
	// Display before
	displaySequence(_vectorData, "Before: ");

	// Sort with vector and measure time
	clock_t start = clock();
	mergeInsertSortVector(_vectorData);
	clock_t end = clock();
	double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	// Sort with deque and measure time
	start = clock();
	mergeInsertSortDeque(_dequeData);
	end = clock();
	double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	// Display after
	displaySequence(_vectorData, "After:  ");

	// Display timing
	std::cout << "Time to process a range of " << _vectorData.size()
			<< " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size()
			<< " elements with std::deque : " << dequeTime << " us" << std::endl;
}