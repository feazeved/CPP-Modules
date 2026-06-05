#include <iostream>
#include <string>

#include "Cat.hpp"

Cat::Cat() :
	Animal("Cat")
{
	std::cout << "[Cat] DEFAULT constructor called!\n";
}

Cat::Cat(const Cat& other) :
	Animal(other)
{
	std::cout << "[Cat] COPY constructor called!\n";
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] ASSIGNMENT constructor called!\n";
	if (this == &other)
		return (*this);

	Animal::operator=(other);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat] DESTRUCTOR called!\n";
}

void	Cat::makeSound() const
{
	std::cout << "[Cat] Meow meow!\n";
}
