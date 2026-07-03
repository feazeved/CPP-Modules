#pragma once

#include <string>
#include <stack>

class RPN {
public:
	RPN();
	RPN(std::string& arg);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();


private:
	std::stack<char>	s;

	static void	trimSpaces(std::string& arg);
};
