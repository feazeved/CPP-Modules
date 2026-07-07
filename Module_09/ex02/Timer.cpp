#include <iostream>

#include "Timer.hpp"

Timer::Timer() : start(std::clock()) {}

Timer::Timer(std::ostringstream& oss) : start(std::clock()), oss(&oss) {}

Timer::Timer(const Timer& other) :
	start(other.start) {}

Timer&	Timer::operator=(const Timer& other)
{
	if (this == &other)
		return (*this);

	start = other.start;

	return (*this);
}

Timer::~Timer()
{
	std::clock_t	end = std::clock();

	double elapsed = static_cast<double>(end - start);

	if (!oss)
		std::cout << elapsed << " us\n";
	else
		*oss << elapsed << " us\n";
}
