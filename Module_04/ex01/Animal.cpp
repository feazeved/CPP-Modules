#include <iostream>
#include <string>

#include "Animal.hpp"

Animal::Animal() :
	type("Placeholder")
{
	std::cout << "[Animal] DEFAULT constructor called!\n";
}

Animal::Animal(const std::string& t) :
	type(t)
{
	std::cout << "[Animal] DEFAULT constructor called!\n";
}

Animal::Animal(const Animal& other)
{
	type = other.type;
	std::cout << "[Animal] COPY constructor called!\n";
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "[Animal] ASSIGNMENT constructor called!\n";
	if (this == &other)
		return (*this);

	type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[Animal] DESTRUCTOR called!\n";
}

void	Animal::makeSound() const
{
	std::cout << "[Animal] Generic animal sound.\n";
}

std::string Animal::getIdea(size_t i) const { (void)i; return (""); }
void        Animal::setIdea(size_t i, const std::string& idea) { (void)i; (void)idea;}

std::string	Animal::getType() const { return (type); }
