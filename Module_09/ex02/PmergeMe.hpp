#pragma once

class PmergeMe {
public:
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	enum	Type {
		
	}
	
	
	
	static void	printContainer();

	static void	sort();


private:
	static void	sortList();
	static void	sortVector();
	PmergeMe();
};
