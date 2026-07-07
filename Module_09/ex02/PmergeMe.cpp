#include <limits>
#include <cerrno>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

#include "PmergeMe.hpp"

static bool	isIntRange(long int value);

// ----- Orthodox Canonical Implementation -----
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char** args)
{
	loadVector(args);
	loadList(args);
}

PmergeMe::PmergeMe(const PmergeMe& other) : v(other.v), l(other.l) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this == &other)
		return (*this);

	v = other.v;
	l = other.l;

	return (*this);
}

PmergeMe::~PmergeMe() { }


// ----- Static File Functions -----
static bool	isPositiveIntRange(long int value)
{
	if (errno == ERANGE)
		return (false);
	else if (value < 0 || value > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

// ----- Public Methods -----
void	PmergeMe::loadVector(char** args)
{
	errno = 0;
	for (int i = 0; args[i] != NULL; i++)
	{
		char*	endptr = NULL;
		long int	value = std::strtol(args[i], &endptr, 10);
		if (*endptr != '\0' || !isPositiveIntRange(value))
			throw std::runtime_error("invalid number");
		if (std::find(v.begin(), v.end(), value) != v.end())
			throw std::runtime_error("duplicates are not allowed");
		v.push_back(static_cast<int>(value));
	}
}

void	PmergeMe::loadList(char** args)
{
	errno = 0;
	for (int i = 0; args[i] != NULL; i++)
	{
		char*	endptr = NULL;
		long int	value = std::strtol(args[i], &endptr, 10);
		if (*endptr != '\0' || !isPositiveIntRange(value))
			throw std::runtime_error("invalid number");
		if (std::find(v.begin(), v.end(), value) != v.end())
			throw std::runtime_error("duplicates are not allowed");
		l.push_back(static_cast<int>(value));
	}
}

void	PmergeMe::sortVector()
{
	if (v.size() <= 1)
		return ;

	typedef std::vector<int>::const_iterator const_iterator;

	std::vector<int>	big;
	std::vector<int>	small;

	const bool	odd = v.size() % 2 != 0;

	for (const_iterator it = v.begin(); (it + 1) != v.end(); it += 2) {
		if (*it > *(it + 1)) {
			big.push_back(*it);
			small.push_back(*(it + 1));
		} else {
			big.push_back(*(it + 1));
			small.push_back(*it);
		}
	}

	int single;
	if (odd)
		single = v.back();

	sortVector(big);



}

void	PmergeMe::sortList()
{

}

const std::vector<int>&	PmergeMe::getV() const { return (v); }
const std::list<int>&	PmergeMe::getL() const { return (l); }
