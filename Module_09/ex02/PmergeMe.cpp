#include <limits>
#include <cerrno>
#include <cstdlib>
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
static bool	isIntRange(long int value)
{
	if (errno == ERANGE)
		return (false);
	else if (value < std::numeric_limits<int>::min()
			|| value > std::numeric_limits<int>::max())
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
		if (*endptr != '\0' || !isIntRange(value))
			throw std::runtime_error("invalid number");
		v.push_back(value);
	}
}

void	PmergeMe::loadList(char** args)
{
	errno = 0;
	for (int i = 0; args[i] != NULL; i++)
	{
		char*	endptr = NULL;
		long int	value = std::strtol(args[i], &endptr, 10);
		if (*endptr != '\0' || !isIntRange(value))
			throw std::runtime_error("invalid number");
		l.push_back(value);
	}
}

const std::vector<int>&	PmergeMe::getV() const { return (v); }
const std::list<int>&	PmergeMe::getL() const { return (l); }


void	PmergeMe::sortVector()
{

}

void	PmergeMe::sortList()
{

}
