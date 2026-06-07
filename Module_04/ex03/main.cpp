#include <iostream>
#include <new>

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	IMateriaSource* src = NULL;
	ICharacter*		me = NULL;
	ICharacter*		bob = NULL;
	AMateria*		tmp = NULL;

	std::cout << "-----Subject main-----\n";
	try {
		src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		me = new Character("me");

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		bob = new Character("bob");

	} catch (const std::bad_alloc& e) {
		delete bob;
		delete me;
		delete src;

		std::cerr << "Problem when allocating memory.\n";
		return (1);
	}

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "\n\n-----Testing MateriaSource deep copies-----\n";

	MateriaSource*	book = NULL;
	MateriaSource*	book2 = NULL;
	ICharacter*		Felipe = NULL;
	ICharacter*		Wallace = NULL;

	try {
		Felipe = new Character("felipe");
		Wallace = new Character("wallace");

		book = new MateriaSource();

		book->learnMateria(new Ice());
		book2 = new MateriaSource(*book);
		book->learnMateria(new Cure());

		Felipe->equip(book->createMateria("ice"));
		Felipe->equip(book->createMateria("cure"));

		Wallace->equip(book2->createMateria("ice"));
		Wallace->equip(book2->createMateria("cure"));

	} catch (const std::bad_alloc& e) {

		delete Felipe;
		delete Wallace;
		delete book;
		delete book2;

		std::cerr << "Problem when allocating memory.\n";
		return (1);
	}

	Felipe->use(0, *Wallace);
	Felipe->use(1, *Wallace);

	Wallace->use(0, *Felipe);
	Wallace->use(1, *Felipe);

	delete book;
	delete book2;

	std::cout << "\n\n-----Testing Character & AMateria deep copies-----\n";
	Felipe->use(1, *Wallace);
	Wallace->use(0, *Felipe);

	ICharacter*	copy = NULL;

	try {
		copy = new Character(*dynamic_cast<Character*>(Felipe));

	} catch (const std::bad_alloc& e) {

		delete copy;

		std::cerr << "Problem when allocating memory.\n";
		return (1);
	}

	std::cout << "Copy's name: " << copy->getName() << "\n";

	copy->unequip(0);

	std::cout << "Copy: ";
	copy->use(0, *Wallace);

	std::cout << "\nFelipe: ";
	Felipe->use(0, *Wallace);

	return (0);
}
