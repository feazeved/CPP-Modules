#include <cstddef>
#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const size_t	num_animals = 4;
	const Animal*	arr[num_animals] = {NULL};

	try {
		std::cout << "-----DOG constructors-----\n";
		for (size_t i = 0; i < num_animals / 2; i++){
			arr[i] = new Dog();
			std::cout << "\n";
		}

		std::cout << "\n\n-----CAT constructors-----\n";
		for (size_t i = num_animals / 2; i < num_animals; i++){
			arr[i] = new Cat();
			std::cout << "\n";
		}
	} catch (const std::bad_alloc& e) {
		std::cerr << "*FAILURE WHEN ALLOCATING, ABBORTING*\n";

		for (size_t i = 0; i < num_animals; i++)
			if (arr[i] != NULL)
				delete arr[i];
		return (1);
	}


	std::cout << "\n\n-----DESTRUCTING as animals-----\n";
	for (size_t i = 0; i < num_animals; i++){
		delete arr[i];
		std::cout << "\n";
	}


	Dog*	dog = NULL;
	Dog*	copy = NULL;

	try {
		std::cout << "\n\n-----TESTING SHALLOW COPIES as dogs-----\n";

		dog = new Dog();
		std::cout << "\n";
		copy = new Dog(*dog);

	} catch (const std::bad_alloc& e) {
		std::cerr << "*FAILURE WHEN ALLOCATING, ABBORTING*\n";

		if (dog)
			delete dog;
		if (copy)
			delete copy;
		return (1);
	}


		dog->getBrain()->setIdea(0, "blue");
		std::cout << "\noriginal's idea: " << dog->getBrain()->getIdea(0) << "\n";
		std::cout << "copy's idea: " << copy->getBrain()->getIdea(0) << "\n";
		std::cout << "\nChanging value at copy...\n\n";
		copy->getBrain()->setIdea(0, "red");
		std::cout << "original's idea: " << dog->getBrain()->getIdea(0) << "\n";
		std::cout << "copy's idea: " << copy->getBrain()->getIdea(0) << "\n";

		std::cout << "\n-----TESTING ASSIGNMENT-----\n";
		*copy = *dog;
		std::cout << "\noriginal's idea: " << dog->getBrain()->getIdea(0) << "\n";
		std::cout << "assignment's idea: " << copy->getBrain()->getIdea(0) << "\n";


		std::cout << "\n-----DESTRUCTORS-----\n";
		delete dog;
		std::cout << "\n";
		delete copy;

	return (0);
}
