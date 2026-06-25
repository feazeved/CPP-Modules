#pragma once

#include <cstddef>

template <typename T>
void	iter(T* array, const size_t length, void (*func)(T&))
{
	if (!array || !func)
		return ;

	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template <typename T>
void	iter(T* array, const size_t length, void (*func)(const T&))
{
	if (!array || !func)
		return ;

	for (size_t i = 0; i < length; i++)
		func(array[i]);
}
