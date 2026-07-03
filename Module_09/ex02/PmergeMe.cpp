#include "PmergeMe.hpp"

// ----- Orthodox Canonical Implementation -----
PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe& other) :
	v(other.v), l(other.l) { }

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this == &other)
		return (*this);

	v = other.v;
	l = other.l;

	return (*this);
}

PmergeMe::~PmergeMe() { }

