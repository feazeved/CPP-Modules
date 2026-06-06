#include <cstddef>
#include <iostream>

#include "Brain.hpp"

Brain::Brain() :
	ideas()
{
	std::cout << "[Brain] DEFAULT constructor called!\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "[Brain] COPY constructor called!\n";
	for (size_t i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "[Brain] ASSIGNMENT constructor called!\n";

	if (this == &other)
		return (*this);

	for (size_t i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "[Brain] DESTRUCTOR called!\n";
}

std::string	Brain::getIdea(size_t i) const
{
	if (i > 99)
		return ("");
	return (ideas[i]);
}

void		Brain::setIdea(size_t i, const std::string& n_idea)
{
	if (i > 99)
		return ;
	ideas[i] = n_idea;
}
