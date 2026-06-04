#include <cstddef>
#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const size_t	num_animals = 4;
	const Animal*	arr[num_animals];

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


	std::cout << "\n\n-----DESTRUCTING as animals-----\n";
	for (size_t i = 0; i < num_animals; i++){
		delete arr[i];
		std::cout << "\n";
	}


	std::cout << "\n\n-----TESTING SHALLOW COPIES as animals-----\n";
	Dog	first;
	Dog	assign;


	first.setIdea(0, "pedrinho");
	std::cout << first.getIdea(0) << "\n\n\n";

	assign = first;

	std::cout << assign.getIdea(0) << "\n";
	assign.setIdea(0, "wallacinho");

	std::cout << first.getIdea(0) << "\n";

	return (0);
}
