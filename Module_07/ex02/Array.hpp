#pragma once

#include <cstddef>

template <class T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	T&			operator[](unsigned int n);
	const T&	operator[](unsigned int n) const;

	size_t	size() const;

private:
	T*				array;
	unsigned int	length;
};

#include "Array.tpp"
