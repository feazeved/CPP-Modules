#include <cstdlib>
#include <ctime>
#include <iterator>
#include <vector>
#include <cstddef>
#include <typeinfo>

#include "easyfind.hpp"

template <typename T>
static void	printVector(const std::vector<T> v)
{
	typename std::vector<T>::const_iterator	it = v.begin();
	typename std::vector<T>::const_iterator	ite = v.end();

	for (; it != ite; it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

template <typename T>
void	test(const T toFind)
{
	std::cout << "\n\n===== Testing " << typeid(T).name() << " vector =====\n";

	const std::size_t	size = 13;

	std::vector<T>	v(size);

	for (unsigned int i = 0; i < size; i++) {
		v[i] = rand() % 26 + 97;
	}

	printVector(v);

	typename std::vector<T>::iterator	it = ::easyfind(v, toFind);

	std::cout << "easyfind: ";
	if (it != v.end())
		std::cout << "Value at index " << std::distance(v.begin(), it);
	else
		std::cout << "value not found";
	std::cout << std::endl;
}

int	main()
{
	srand((unsigned)time(NULL));

	test<char>(97);
	test<int>(97);
	test<double>(97);
	test<float>(97);
}
