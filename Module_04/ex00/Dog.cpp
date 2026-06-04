#include <iostream>
#include <string>

#include "Dog.hpp"

Dog::Dog() :
	Animal("Dog")
{
	std::cout << "[Dog] DEFAULT constructor called!\n";
}

Dog::Dog(const Dog& other)
{
	type = other.type;
	std::cout << "[Dog] COPY constructor called!\n";
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] ASSIGNMENT constructor called!\n";
	if (this == &other)
		return (*this);

	type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog] DESTRUCTOR called!\n";
}

void	Dog::makeSound() const
{
	std::cout << "[Dog] Bark bark!\n";
}
