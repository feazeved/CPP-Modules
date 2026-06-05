#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		std::string	getIdea(size_t i) const;
		void		setIdea(size_t i, const std::string& n_idea);
	private:
		std::string	ideas[100];

};

#endif
