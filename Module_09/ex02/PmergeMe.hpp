#pragma once

#include <vector>
#include <list>

class PmergeMe {
public:

	static std::vector<int>&	loadVector(char** argv);
	static std::list<int>&		loadList(char** argv);

	// static void	sortVector(std::vector<int>& v);
	// static void	sortList(std::list<int>& l);


private:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	std::vector<int>	v;
	std::list<int>		l;
};
