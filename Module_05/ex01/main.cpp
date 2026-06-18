#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	Bia("Bia", 3);
	Bureaucrat	Felipe("Felipe", 20);

	std::cout << "\n-----Testing forms-----\n\n";
	try {
		Form		Arara("Arara", 15, 5);

		std::cout << Bia << "\n";
		std::cout << Arara << "\n";

		Felipe.signForm(Arara);
		Bia.signForm(Arara);

		std::cout << "\n";
		std::cout << Arara;


	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	std::cout << std::endl;

	return (0);
}
