#pragma once

#include <ctime>

class	Timer {
public:
	Timer();
	Timer(const Timer& other);
	Timer&	operator=(const Timer& other);
	~Timer();

private:
	std::clock_t	start;
};
