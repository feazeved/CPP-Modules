#include <iostream>
#include <new>
#include <string>

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() :
	Animal("Dog")
{
	brain = new Brain();
	std::cout << "[Dog] DEFAULT constructor called!\n";
}

Dog::Dog(const Dog& other) :
	Animal(other)
{
	std::cout << "[Dog] COPY constructor called!\n";
	if (!other.brain)
		brain = NULL;
	else
		brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] ASSIGNMENT constructor called!\n";
	if (this == &other)
		return (*this);

	Animal::operator=(other);

	if (!other.brain)
	{
		delete brain;
		brain = NULL;
	}
	else
	{
		if (brain == NULL)
			brain = new Brain();
		*this->brain = *other.brain;
	}

	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "[Dog] DESTRUCTOR called!\n";
}

void	Dog::makeSound() const
{
	std::cout << "[Dog] Bark bark!\n";
}

Brain*	Dog::getBrain() const { return (brain); }
