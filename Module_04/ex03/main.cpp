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

		delete bob; delete me; delete src;

		std::cerr << "Problem when allocating memory.\n";
		return (1);
	}

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob; delete me; delete src;

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

		Felipe->equip(book->createMateria("cure"));
		Felipe->equip(book->createMateria("ice"));

		Wallace->equip(book2->createMateria("ice"));
		Wallace->equip(book2->createMateria("cure"));

	} catch (const std::bad_alloc& e) {

		delete Felipe; delete Wallace; delete book; delete book2;

		std::cerr << "Problem when allocating memory.\n";
		return (1);
	}

	std::cout << "Felipe: ";
	Felipe->use(0, *Wallace);
	std::cout << "Felipe: ";
	Felipe->use(1, *Wallace);

	std::cout << "Wallace: ";
	Wallace->use(0, *Felipe);
	std::cout << "Wallace: ";
	Wallace->use(1, *Felipe);

	delete book; delete book2;

	std::cout << "\n\n-----Testing Character & AMateria deep copies-----\n";
	Felipe->use(0, *Wallace);
	Wallace->use(0, *Felipe);

	ICharacter*	Copy = NULL;

	try {
		Copy = new Character(*dynamic_cast<Character*>(Felipe));
		*dynamic_cast<Character*>(Wallace) = *dynamic_cast<Character*>(Felipe);

	} catch (const std::bad_alloc& e) {

		delete Copy; delete Felipe; delete Wallace;

		std::cerr << "Problem when allocating memory.\n";
		return (1);
	}

	std::cout << "Copy's name: " << Copy->getName() << "\n";

	Copy->unequip(0);

	std::cout << "Copy: ";
	Copy->use(0, *Wallace);

	std::cout << "\nFelipe: ";
	Felipe->use(0, *Wallace);

	std::cout << "Wallace's name: " << Wallace->getName() << "\n";
	Wallace->use(1, *Felipe);


	std::cout << "\n\n-----Testing different behaviours-----\n";

	try {
		Wallace->equip(new Ice());
		Wallace->equip(new Ice());
		Wallace->equip(new Ice());
		Wallace->equip(new Cure());
		Copy->equip(new Cure());

	} catch (const std::bad_alloc& e) {

		delete Felipe; delete Wallace; delete Copy;

		std::cerr << "Problem when allocating memory.\n";
		return (1);
	}

	std::cout << "Wallace: ";
	Wallace->use(-1, *Felipe);
	std::cout << "\n";

	std::cout << "Wallace: ";
	Wallace->use(0, *Felipe);

	std::cout << "Wallace: ";
	Wallace->use(1, *Felipe);

	std::cout << "Wallace: ";
	Wallace->use(2, *Felipe);

	std::cout << "Wallace: ";
	Wallace->use(3, *Felipe);

	std::cout << "Wallace: ";
	Wallace->use(4, *Felipe);
	std::cout << "\n";

	delete Felipe; delete Wallace; delete Copy;

	return (0);
}
