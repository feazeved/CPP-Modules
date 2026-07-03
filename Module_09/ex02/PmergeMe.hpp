#pragma once

#include <list>
#include <vector>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();


private:
	std::vector<int>	v;
	std::list<int>		l;
};
