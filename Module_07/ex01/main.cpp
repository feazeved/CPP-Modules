#include <iostream>
#include <string>

#include "iter.hpp"

template<typename A>
void	doublevalue(A& arg)
{
	arg *= 2;
}

template<typename T>
void	printArray(T* array, const size_t length)
{
	for (size_t i = 0; i < length; i++)
		std::cout << array[i] << " ";
	std::cout << "\n";
}

void	toUpperChar(char& c)
{
	c = std::toupper(static_cast<unsigned char>(c));
}

int	main()
{
	const size_t	len = 5;
	std::string		str("teste");
	int				arr[len] = {0, 1, 2, 3, 4};

	std::cout << "\n===== Testing common function =====\n";
	std::cout << "str before: " << str << "\n";

	::iter(&str[0], str.length(), ::toUpperChar);
	std::cout << "str after : " << str << "\n";


	std::cout << "\n===== Testing instantiated template function =====\n";
	std::cout << "arr before: ";
	::printArray(arr, len);

	::iter(arr, len, ::doublevalue<int>);

	std::cout << "arr after : ";
	::printArray(arr, len);

	std::cout << std::endl;
	return (0);
}
