#pragma once

#include <stdint.h>

#include "Data.hpp"

class Serializer {
public:
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer();
};
