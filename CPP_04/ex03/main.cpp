/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:21:43 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/09 16:31:59 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Colors
# define GREY		"[90m"
# define C_RES		"[0m"
# define YELLOW		"[33m"
# define BLUE		"[34m"
# define COLOR(id)	"[38;5;"#id"m"
# define CORAIL		COLOR(168)
# define ORANGE		COLOR(130)
# define SKY_BLUE	COLOR(69)
# define GREEN_B	"[32;01m"
# define RED 		"[31m"

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <string>
#include <iostream>

void	test_xp()
{
Character bill("bill");

	AMateria	*ice = new Ice();
	AMateria	*cure = new Cure();
	AMateria	*icy = new Ice();
	AMateria	*cury = new Cure();

	bill.equip(ice);//index0
	bill.equip(cure);//index1
	bill.equip(icy);//index2

	bill.use(0, bill);//ice
	bill.use(1, bill);//cure
	bill.use(2, bill);//icy
	bill.use(3, bill);//non equip

	std::cout << "index 0: ice   " << ice->getXP() << " " << ice->getType() << std::endl;
	std::cout << "index 1: cure  "<< cure->getXP() << " " << cure->getType() << std::endl;
	std::cout << "index 2: icy  "<< icy->getXP() << " " << icy->getType() << std::endl;
	std::cout << "index 3: (non eq) "<< cury->getXP() << " " << cury->getType() << std::endl;
	bill.equip(cury);//index3
	bill.equip(ice);//index4 equip too much
	bill.equip(icy);//index5 equip too much
	bill.use(0, bill);//ice
	bill.use(1, bill);//cure
	bill.use(2, bill);//icy
	bill.use(3, bill);//cury
	bill.use(4, bill);// equip too much index does not exist
	bill.use(5, bill);//equip too much index does not exist
	bill.use(10, bill);// index does not exist
	bill.use(-1, bill);// negative index does not exist 

	std::cout << "index 0: ice   " << ice->getXP() << " " << ice->getType() << std::endl;
	std::cout << "index 1: cure  "<< cure->getXP() << " " << cure->getType() << std::endl;
	std::cout << "index 2: icy  "<< icy->getXP() << " " << icy->getType() << std::endl;
	std::cout << "index 3: cury "<< cury->getXP() << " " << cury->getType() << std::endl;
	bill.unequip(2);//unequip index2 ->(ex icy)
	bill.use(0, bill);//ice
	bill.use(1, bill);//cure
	bill.use(2, bill);//unequipe (ex icy)
	bill.use(3, bill);//cury
	std::cout << "index 0: ice   " << ice->getXP() << " " << ice->getType() << std::endl;
	std::cout << "index 1: cure  " << cure->getXP() << " " << cure->getType() << std::endl;
	std::cout << "index 2: icy (uneq)  " << icy->getXP() << " " << icy->getType() << std::endl;
	std::cout << "index 3: cury " << cury->getXP() << " " << cury->getType() << std::endl;
	bill.unequip(3);///unequip index2 ->(ex cury)
	bill.equip(cury);//cury equip on index 2 because index 2 and 3 was unequip
	bill.use(0, bill);//ice
	bill.use(1, bill);//cure
	bill.use(2, bill);//cury
	bill.use(3, bill);//unequip
	std::cout << "index 0: ice   " << ice->getXP() << " " << ice->getType() << std::endl;
	std::cout << "index 1: cure  " << cure->getXP() << " " << cure->getType() << std::endl;
	std::cout << "index 2: cury " << cury->getXP() << " " << cury->getType() << std::endl;
	std::cout << "index 3: icy (uneq) " << icy->getXP() << " " << icy->getType() << std::endl;
}

void	subject_test()
{
	IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;

}

int main()
{
	std::cout << BLUE << "----------Test XP ------------" << C_RES << std::endl;
	std::cout << std::endl;
	test_xp();
	std::cout << std::endl;
	std::cout << BLUE << "----------Test Subject -------" << C_RES << std::endl;
	std::cout << std::endl;
	
	subject_test();
	std::cout << std::endl;

	std::cout << BLUE << "-- Creating MateriaSource and learning two materias --" << C_RES << std::endl;
	std::cout << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
	std::cout << std::endl;

	std::cout << BLUE << "-- Creating Character \"me\" and equipping materials --" << C_RES << std::endl;
	std::cout << std::endl;
		Character* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->use(1, *me);
		std::cout << "tmp (equiped on 1) XP is: " << tmp->getXP() << std::endl;

	std::cout << std::endl;


	std::cout << BLUE << "-- Creating ICharacter \"me2\" from a copy of me and deleting me to prove deep copy --" << C_RES << std::endl;
		ICharacter* me2 = new Character(*me);
		delete me;
	std::cout << std::endl;

	std::cout << BLUE << "-- creating ice and cure and equipping more (testing with too much) Materia --" << C_RES << std::endl;

		
		AMateria *cure = new Cure;
		AMateria *ice = new Ice;
		AMateria *cury = new Cure;
		AMateria *icy = new Ice;
	//	ICharacter *bob = new Character("Bob");

		me2->equip(tmp); //cure
		me2->equip(ice);
		me2->equip(icy);

		std::cout << "Cure(equiped on 0) XP is: " << cure->getXP() << std::endl;
		std::cout << "Ice (equipped on 1) XP is: " << ice->getXP() << std::endl;
		std::cout << "Icy (equipped on 2) XP is: " << icy->getXP() << std::endl;
		std::cout << "Cury (unequipped) XP is: " << cury->getXP() << std::endl;
	
	std::cout << std::endl;

	std::cout << BLUE << "-- using all equiped materias on new ICharacter bob -- " << C_RES << std::endl;
		ICharacter *bob = new Character("Bob");
		me2->use(0, *bob);
		me2->use(1, *bob);
		me2->use(2, *bob);
		me2->use(3, *bob);
		me2->use(10, *bob);
		me2->use(-1, *bob);
		std::cout << "Cure(equiped on 0) XP is: " << cure->getXP() << std::endl;
		std::cout << "Ice (equipped on 1) XP is: " << ice->getXP() << std::endl;
		std::cout << "Icy (equipped on 2) XP is: " << icy->getXP() << std::endl;
		std::cout << "Cury (unequipped) XP is: " << cury->getXP() << std::endl;
	std::cout << std::endl;


	std::cout << BLUE << "-- unequiping materias 2 and 3 and trying again --" << C_RES << std::endl;
	std::cout << std::endl;
		me2->unequip(2);//icy
		me2->unequip(3);

		me2->use(0, *bob);
		me2->use(1, *bob);
		me2->use(2, *bob);
		me2->use(3, *bob);
		me2->use(10, *bob);
		me2->use(-1, *bob);
		std::cout << "Cure (equiped on 0) XP is: " <<cure->getXP() << std::endl;
		std::cout << "Ice(equiped on 1) XP is: " << ice->getXP() << std::endl;
		std::cout << "Icy (unequipped) XP is: " << icy->getXP() << std::endl;
		std::cout << "Cury(unequipped) XP is: " << cury->getXP() << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << "-- requipping materias 2 and 3 in new order and trying again" << C_RES << std::endl;
		me2->equip(cury);//index2
		me2->equip(icy); //index3

		me2->use(0, *bob);
		me2->use(1, *bob);
		me2->use(2, *bob);
		me2->use(3, *bob);
		me2->use(10, *bob);
		me2->use(-1, *bob);
		std::cout << "Cure (equiped on 0) XP is: " << cure->getXP() << std::endl;
		std::cout << "Ice (equiped on 1) XP is: " << ice->getXP() << std::endl;
		std::cout << "Cury (equiped on 2) XP is: " << cury->getXP() << std::endl;
		std::cout << "Icy (equiped on 3) XP is: " << icy->getXP() << std::endl;
	std::cout << std::endl;

	std::cout << BLUE << "-- Deleting bob, me2 and the MateriaSource --" << C_RES << std::endl;
		delete bob;
		delete me2;
		delete src;
	std::cout << std::endl;

	return (0);
}
