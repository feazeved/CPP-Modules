#pragma once

#include <iostream>
#include <algorithm>

#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T& container, int toFind)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), toFind);

	if (it == container.end())
		return (container.end());

	return (it);
}
