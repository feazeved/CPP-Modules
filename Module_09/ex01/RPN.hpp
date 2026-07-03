#pragma once

#include <string>
#include <stack>
#include <utility>

class RPN {
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	enum Type {
		Char,
		Int
	};

	void	calcExpr(std::string& arg);

private:
	std::stack<std::pair<Type, int> >	s;
	int					result;

	int	doOp(char op);
};
