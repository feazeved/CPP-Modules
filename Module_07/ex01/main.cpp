#include <iostream>
#include <string>

#include "iter.hpp"

template<typename A>
void	doublevalue(A& arg)
{
	arg *= 2;
}

void	toUpperChar(char& c)
{
	//c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
	c = std::toupper(c);
}

#define FT_LEN 5

int	main()
{
	std::string	str = "teste";
	int			arr[FT_LEN] = {0, 1, 2, 3, 4};

	::iter(&str[0], str.length(), ::toUpperChar);
	std::cout << str << "\n";

	::iter(arr, FT_LEN, ::doublevalue<int>);
	for (int i = 0; i < FT_LEN; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
	return (0);
}
