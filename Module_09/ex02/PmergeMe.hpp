#pragma once

#include <vector>
#include <deque>

class PmergeMe {
public:

	static std::vector<int>&	loadVector(char** argv);
	static std::deque<int>&		loadDeque(char** argv);


	template <class C>
	static void	sort(C& c);

private:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
};
