#pragma once

#include <string>
#include <stack>

class RPN {
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void	calcExpr(std::string& arg);

private:
	std::stack<int>		s;

	int	doOp(char op);
};
