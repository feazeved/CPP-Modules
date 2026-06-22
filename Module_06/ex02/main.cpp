#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	random = rand() % 3;

	try {
		if (random == 1)
		{
			A*	a = new A();
			return (dynamic_cast<Base*>(a));
		}
		else if (random == 2)
		{
			B*	b = new B();
			return (dynamic_cast<Base*>(b));
		}
		else
		{
			C*	c = new C();
			return (dynamic_cast<Base*>(c));
		}
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << "\n"
				  << "generate() -> NULL\n";

		return (NULL);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "I'm an A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "I'm a B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "I'm a C\n";
	else
		std::cerr << "Not implemented class.\n";
}

void	identify(Base& p)
{
	try {
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "I'm an A\n";
		return ;
	} catch (const std::exception&) { }

	try {
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "I'm a B\n";
		return ;
	} catch (const std::exception&) { }

	try {
		C&	c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "I'm a C\n";
		return ;
	} catch (const std::exception&) { }

	std::cerr << "Not implemented class.\n";
}

int	main()
{
	A		a;
	B		b;
	C		c;

	srand((unsigned) time(NULL));

	Base*	base = generate();
	if (base == NULL)
		return (1);

	std::cout << "\n=====Testing random generated class=====\n";
	identify(base);

	std::cout << "\n=====Testing a, b and c=====\n";
	identify(a);
	identify(b);
	identify(c);

	std::cout << std::endl;
	return (0);
}
