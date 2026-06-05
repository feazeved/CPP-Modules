#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :
	type("Placeholder")
{
	std::cout << "[WrongAnimal] DEFAULT constructor called!\n";
}

WrongAnimal::WrongAnimal(const std::string& t) :
	type(t)
{
	std::cout << "[WrongAnimal] DEFAULT constructor called!\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	type = other.type;
	std::cout << "[WrongAnimal] COPY constructor called!\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "[WrongAnimal] ASSIGNMENT constructor called!\n";
	if (this == &other)
		return (*this);

	type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] DESTRUCTOR called!\n";
}

void	WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] Generic WrongAnimal sound.\n";
}

std::string	WrongAnimal::getType() const { return (type); }