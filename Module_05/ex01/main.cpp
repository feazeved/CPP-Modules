#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try {
		Bureaucrat	Bia("Bia", 5);
		Bureaucrat	Felipe("Felipe", 11);
		Form		Arara("Arara", 10, 10);

		std::cout << Bia;
		std::cout << Arara;

		Bia.signForm(Arara);
		Felipe.signForm(Arara);

		std::cout << Arara;


	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n";
	}

	return (0);
}
