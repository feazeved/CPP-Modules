#pragma once

#include <iostream>
#include <exception>
#include <string>

#include "Array.hpp"

// ----- Orthodox Canonical Implementation -----
template <typename T>
Array<T>::Array() :  array(NULL), length(0)
{
	array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) : array(NULL), length(n)
{
	array = new T[n];
	for (unsigned int i = 0; i < length; i++)
		array[i] = 0;
}

template <typename T>
Array<T>::Array(const Array& other) : array(NULL), length(other.length)
{
	if (other.array)
	{
		array = new T[other.length];
		for (unsigned int i = 0; i < length; i++)
			array[i] = other.array[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return (*this);

	if (other.array == NULL)
	{
		delete[] array;
		array = NULL;
	}
	else
	{
		if (array == NULL)
			array = new T[other.length];

		for (unsigned int i = 0; i < other.length; i++)
			array[i] = other.array[i];
	}
	length = other.length;

	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

// ----- [] Operator -----
template <typename T>
T&	Array<T>::operator[](unsigned int n)
{
	if (n >= length)
	{
		throw std::out_of_range("index is out of bounds");
	}

	return (array[n]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int n) const
{
	if (n >= length)
	{
		throw std::out_of_range("index is out of bounds");
	}

	return (array[n]);
}


// ----- Public Methods -----
template <typename T>
size_t	Array<T>::size() const { return (length); }
