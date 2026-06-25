#include <exception>
#include <iostream>

#include "Array.hpp"

static void	printArray(Array<int> arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

int	main()
{
	Array<int>*	original = NULL;
	Array<int>*	assign = NULL;
	Array<int>*	copy = NULL;

	try {
		original = new Array<int>(3);
		assign = new Array<int>(42);

		(*original)[0] = 99;

		*assign = *original;

		(*original)[1] = 100;

		copy = new Array<int>(*original);

		(*original)[2] = 101;

	} catch (const std::exception& e) {
		std::cerr << e.what() << "\n";

		delete original; delete assign; delete copy;
		return (1);
	}

	std::cout << "\n===== Arrays before =====\n";
	std::cout << "main  : "; printArray(*original);
	std::cout << "assign: "; printArray(*assign);
	std::cout << "copy  : "; printArray(*copy);

	(*original)[0] = 67;
	(*original)[1] = 68;
	(*original)[2] = 69;

	(*assign)[0] = 97;
	(*copy)[0] = 98;

	std::cout << "\n\n===== Arrays after =====\n";
	std::cout << "main  : "; printArray(*original);
	std::cout << "assign: "; printArray(*assign);
	std::cout << "copy  : "; printArray(*copy);


	std::cout << "\n\n===== Testing exception =====\n";
	try {
		std::cout << (*assign)[assign->size()];
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}


	std::cout << "\n\n===== Testing empty array =====\n";
	try {
		std::cout << "Creating empty array...\n";

		Array<int>	generic;

		std::cout << "Empty Array size: " << generic.size() << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}


	std::cout << "\n\n===== Testing const instance =====\n";
	try {
		std::cout << "Creating const array...\n\n";

		const Array<int>	cgeneric(*original);

		std::cout << "const Array size: " << cgeneric.size() << "\n"
				  << "const Array [0] : " << cgeneric[0] << "\n";

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	std::cout << std::endl;

	delete original; delete assign; delete copy;

	return (0);
}
