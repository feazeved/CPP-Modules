#pragma once

class PmergeMe {
public:

	template <class C>
	static void	loadContainer(char** args, C& c);

	template <class C>
	static void	sortContainer(C& c);

private:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
};
