#pragma once

#include "MutantStack.hpp"

// ----- Orthodox Canonical Implementation -----
template <typename T, class C>
MutantStack<T, C>::MutantStack() { }

template <typename T, class C>
MutantStack<T, C>::MutantStack(const MutantStack<T, C>& other) :
	std::stack<T, C>(other) { }

template <typename T, class C>
MutantStack<T, C>&	MutantStack<T, C>::operator=(const MutantStack<T, C>& other)
{
	if (*this == &other)
		return (*this);

	std::stack<T, C>::operator=(other);

	return (*this);
}

template <typename T, class C>
MutantStack<T, C>::~MutantStack() { }

// ----- Public methods for iterators -----
template <typename T, class C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::begin()
{
	return (this->c.begin());
}

template <typename T, class C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::end()
{
	return (this->c.end());
}
