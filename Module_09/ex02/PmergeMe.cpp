#include <limits>
#include <cerrno>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

#include "PmergeMe.hpp"

static bool	isPositiveIntRange(long int value);

// ----- Orthodox Canonical Implementation -----
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this); }

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

static std::vector<int> jacobsThal(int n)
{
    std::vector<int> result;

    result.push_back(0);
    result.push_back(1);

    int prev = 1;
    int next = 3;

    while (static_cast<int>(result.size()) < n)
    {
        int rangeEnd   = prev;
        int rangeStart = std::min(next, n - 1);

        for (int i = rangeStart; i > rangeEnd; i--)
        {
            result.push_back(i);
            if (static_cast<int>(result.size()) == n)
                break;
        }

        int newNext = next + 2 * prev;
        prev = next;
        next = newNext;
    }

    return result;
}

// ----- Public Methods -----
std::vector<int>&	PmergeMe::loadVector(char** args)
{
	std::vector<int>*	v = new std::vector<int>();

	errno = 0;
	for (int i = 0; args[i] != NULL; i++)
	{
		char*	endptr = NULL;
		long int	value = std::strtol(args[i], &endptr, 10);
		if (*endptr != '\0' || !isPositiveIntRange(value))
			throw std::runtime_error("invalid number");
		if (std::find(v->begin(), v->end(), value) != v->end())
			throw std::runtime_error("duplicates are not allowed");
		v->push_back(static_cast<int>(value));
	}

	return (*v);
}

std::deque<int>&	PmergeMe::loadDeque(char** args)
{
	std::deque<int>*	d = new std::deque<int>();

	errno = 0;
	for (int i = 0; args[i] != NULL; i++)
	{
		char*	endptr = NULL;
		long int	value = std::strtol(args[i], &endptr, 10);
		if (*endptr != '\0' || !isPositiveIntRange(value))
			throw std::runtime_error("invalid number");
		if (std::find(d->begin(), d->end(), value) != d->end())
			throw std::runtime_error("duplicates are not allowed");
		d->push_back(static_cast<int>(value));
	}

	return (*d);
}

template <class C>
void	PmergeMe::sort(C& c)
{
	if (c.size() <= 1)
		return ;

	typedef typename C::const_iterator const_iterator;

	C	big;
	C	small;

	const bool	odd = c.size() % 2 != 0;

	for (const_iterator it = c.begin(); it != c.end() && (it + 1) != c.end(); it += 2) {
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
		single = c.back();

	sort(big);

	C	sorted = big;

	if (!small.empty())
	{
		std::vector<int>	indexes = jacobsThal(small.size());
		for (std::size_t i = 0; i < small.size(); i++)
		{
			int idx = indexes[i];
			typename C::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), small[idx]);
			sorted.insert(pos, small[idx]);
		}
	}

	if (odd)
	{
		typename C::iterator	pos = std::lower_bound(sorted.begin(), sorted.end(), single);
		sorted.insert(pos, single);
	}

	c = sorted;
}

template void	PmergeMe::sort<std::vector<int> >(std::vector<int>&);
template void	PmergeMe::sort<std::deque<int> >(std::deque<int>&);
