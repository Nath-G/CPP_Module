#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
//#include <string>
//#include <iostream>

int main() {

	std::cout << "1. Creating MateriaSource and learning two materias" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
	std::cout << std::endl;

	std::cout << "2. Creating Character \"mebis\" and equipping materials" << std::endl;
		Character* poppy = new Character("me");
		Character* yeah = new Character("yeah");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		poppy->equip(tmp);
		tmp = src->createMateria("cure");
		poppy->equip(tmp);
		tmp = src->createMateria("fire");
		poppy->equip(tmp);
		poppy->use(0, *yeah);
		poppy->use(1, *yeah);
		poppy->use(2, *yeah);

	std::cout << std::endl;

		delete yeah;
	std::cout << "3. Creating ICharacter \"me\" from a copy of me and deleting me to prove deep copy" << std::endl;
		ICharacter* me = new Character(*poppy);
		delete poppy;
	std::cout << std::endl;

	std::cout << "4. creating ice and cure and equipping more (testing with too much) Materia" << std::endl;
		AMateria *cure = new Cure;
		AMateria *ice = new Ice;

		me->equip(cure);
		me->equip(ice);
		me->equip(cure);
		me->equip(ice);
		me->equip(cure);
		me->equip(ice);
		std::cout << "Ice spell XP is: " << ice->getXP() << std::endl;
		std::cout << "Cure spell XP is: " << cure->getXP() << std::endl;
		
	std::cout << std::endl;

	std::cout << "5. using all equiped materias on new ICharacter bob" << std::endl;
		ICharacter *bob = new Character("Bob");
		me->use(0, *bob);
		me->use(1, *bob);
			std::cout << "Ice XP is: " << ice->getXP() << std::endl;
			std::cout << "Cure  XP is: " << cure->getXP() << std::endl;
		me->use(2, *bob);
		me->use(3, *bob);
			std::cout << "Ice XP is: " << ice->getXP() << std::endl;
			std::cout << "Cure  XP is: " << cure->getXP() << std::endl;
		me->use(10, *bob);
		me->use(-1, *bob);
			std::cout << "Ice XP is: " << ice->getXP() << std::endl;
			std::cout << "Cure XP is: " << cure->getXP() << std::endl;
	std::cout << std::endl;


	std::cout << "6. unequiping materias 2 and 3 and trying again" << std::endl;
		me->unequip(2);
		me->unequip(3);

		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(10, *bob);
		me->use(-1, *bob);
		std::cout << "Ice (unequipped) XP is: " << ice->getXP() << std::endl;
		std::cout << "Cure (unequipped) XP is: " << cure->getXP() << std::endl;
	std::cout << std::endl;

	std::cout << "7. requipping materias 2 and 3 in new order and trying again" << std::endl;
		me->equip(ice);
		me->equip(cure);

		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(10, *bob);
		me->use(-1, *bob);
		std::cout << "Ice XP is: " << ice->getXP() << std::endl;
		std::cout << "Cure XP is: " << cure->getXP() << std::endl;
	std::cout << std::endl;

	std::cout << "8. Deleting bob, me and the MateriaSource" << std::endl;
		delete bob;
		delete me;
		delete src;
	std::cout << std::endl;

	
return (0);
}