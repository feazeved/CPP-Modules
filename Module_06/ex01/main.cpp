#include <iostream>

#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data	data = {.name = "Felipe", .x = 0, .y = 0, .grade = 42};

	std::cout << "\n=====TESTING BEFORE SERIALIZATION=====\n";
	std::cout << "data name: " << data.name << "\n"
			  << "data x: " << data.x << "\n"
			  << "data y: " << data.y << "\n"
			  << "data grade: " << data.grade << "\n";


	uintptr_t reinterpreted = Serializer::serialize(&data);

	Data	newData = *(Serializer::deserialize(reinterpreted));

	std::cout << "\n=====TESTING AFTER SERIALIZATION=====\n";
	std::cout << "data name: " << newData.name << "\n"
			  << "data x: " << newData.x << "\n"
			  << "data y: " << newData.y << "\n"
			  << "data grade: " << newData.grade << "\n";

	std::cout << std::endl;
	return (0);
}
