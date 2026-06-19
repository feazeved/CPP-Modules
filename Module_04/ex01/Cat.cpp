#include <iostream>
#include <string>

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() :
	Animal("Cat")
{
	brain = new Brain();
	std::cout << "[Cat] DEFAULT constructor called!\n";
}

Cat::Cat(const Cat& other) :
	Animal(other)
{
	std::cout << "[Cat] COPY constructor called!\n";
	if (!other.brain)
		brain = NULL;
	else
		brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] ASSIGNMENT constructor called!\n";
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

Cat::~Cat()
{
	delete brain;
	std::cout << "[Cat] DESTRUCTOR called!\n";
}

void	Cat::makeSound() const
{
	std::cout << "[Cat] Meow meow!\n";
}

Brain*	Cat::getBrain() const { return (brain); }
