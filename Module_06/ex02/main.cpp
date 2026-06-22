#include <iostream>
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	srand((unsigned) time(NULL));
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
	if (dynamic_cast<A*>(&p))
		std::cout << "I'm an A\n";
	else if (dynamic_cast<B*>(&p))
		std::cout << "I'm a B\n";
	else if (dynamic_cast<C*>(&p))
		std::cout << "I'm a C\n";
	else
		std::cerr << "Not implemented class.\n";
}

int	main()
{
	A		a;
	B		b;
	C		c;
	Base*	base = generate();
	if (base == NULL)
		return (1);

	identify(base);
	identify(a);
	identify(b);
	identify(c);

	delete base;
	std::cout << std::endl;
	return (0);
}
