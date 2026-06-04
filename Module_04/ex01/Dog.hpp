#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	public:
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();

		void makeSound() const;

		Brain*		getBrain() const;
		std::string getIdea(size_t i) const;
		void        setIdea(size_t i, const std::string& idea);

	private:
		Brain *brain;
};

#endif
