#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "-----Subject constructors-----\n";
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << "\n-----Subject tests-----\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n-----Subject destructors-----\n";
	delete j;
	delete i;
	delete meta;

	std::cout << "\n-----Testing wrong animals-----\n";
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat;

	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	wrongmeta->makeSound();

	delete k;
	delete wrongmeta;

	return (0);
}
