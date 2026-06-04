#include <iostream>
#include <string>

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() :
	Animal("Dog")
{
	brain = new Brain();
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
	delete brain;
	Brain::operator=(other);
	type = other.type;
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

Brain*	Dog::getBrain() const
{
	return (brain);
}

std::string	Dog::getIdea(size_t i) const
{
	if (i > 99)
		return ("");
	return (brain->getIdea(i));
}

void		Dog::setIdea(size_t i, const std::string& n_idea)
{
	if (i > 99)
		return ;
	brain->setIdea(i, n_idea);
}
