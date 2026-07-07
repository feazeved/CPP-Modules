#pragma once

#include <ctime>
#include <sstream>

class	Timer {
public:
	Timer();
	Timer(std::ostringstream& oss);
	Timer(const Timer& other);
	Timer&	operator=(const Timer& other);
	~Timer();

private:
	std::clock_t		start;
	std::ostringstream*	oss;
};
