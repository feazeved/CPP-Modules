#pragma once

#include <vector>
#include <list>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(char** args);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();


	void	loadVector(char** argv);
	void	loadList(char** argv);

	const std::vector<int>&	getV() const;
	const std::list<int>&	getL() const;

	void	sortVector();
	void	sortList();



private:
	std::vector<int>	v;
	std::list<int>		l;
};
