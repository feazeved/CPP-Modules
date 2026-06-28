#pragma once

#include <stack>

template <typename T, class C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
public:
	MutantStack();
	MutantStack(const MutantStack& other);
	MutantStack<T, C>&	operator=(const MutantStack<T, C>& other);
	~MutantStack();

	typedef typename C::iterator iterator;

	iterator begin();
	iterator end();

};

#include "MutantStack.tpp"
