#include <iostream>
#include <string>

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat() :
	WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat] DEFAULT constructor called!\n";
}

WrongCat::WrongCat(const WrongCat& other) :
	WrongAnimal(other)
{
	type = other.type;
	std::cout << "[WrongCat] COPY constructor called!\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "[WrongCat] ASSIGNMENT constructor called!\n";
	if (this == &other)
		return (*this);

	WrongAnimal::operator=(other);

	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] DESTRUCTOR called!\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "[WrongCat] Meow meow!\n";
}
