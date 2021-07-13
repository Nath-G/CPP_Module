/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:21:43 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/13 09:53:40 by nagresel         ###   ########.fr       */
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
	
	std::cout << BLUE << "----------index 3 unequiped ------------" << C_RES << std::endl;

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
	std::cout << std::endl;
	
	std::cout << BLUE << "----------index 3 and following (so too much) equiped ------------" << C_RES << std::endl;	
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
	std::cout << std::endl;
	
	std::cout << BLUE << "----------index 2 unquiped ------------" << C_RES << std::endl;
	bill.unequip(2);//unequip index2 ->(ex icy)
	bill.use(0, bill);//ice
	bill.use(1, bill);//cure
	bill.use(2, bill);//unequipe (ex icy)
	bill.use(3, bill);//cury
	std::cout << "index 0: ice   " << ice->getXP() << " " << ice->getType() << std::endl;
	std::cout << "index 1: cure  " << cure->getXP() << " " << cure->getType() << std::endl;
	std::cout << "index 2: icy (uneq)  " << icy->getXP() << " " << icy->getType() << std::endl;
	std::cout << "index 3: cury " << cury->getXP() << " " << cury->getType() << std::endl;
	std::cout << std::endl;
	
	std::cout << BLUE << "----------index 3 unquiped then equip again (so index 2) ------------" << C_RES << std::endl;
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
	std::cout << CORAIL << "************* Test XP *************" << C_RES << std::endl;
	std::cout << std::endl;
	test_xp();
	std::cout << std::endl;
	std::cout << CORAIL << "************* Test Subject *************" << C_RES << std::endl;
	std::cout << std::endl;
	
	subject_test();
	std::cout << std::endl;

	std::cout << CORAIL << "************* Others tests *************" << C_RES << std::endl;
	std::cout << std::endl;
	
	std::cout << BLUE << "-- Creating MateriaSource and learning two materias --" << C_RES << std::endl;
	std::cout << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
	std::cout << std::endl;

	std::cout << BLUE << "-- Creating Character \"me\" \"Bob\" and equipping materials --" << C_RES << std::endl;
	std::cout << std::endl;
		Character* me = new Character("me");
		ICharacter *bob = new Character("Bob");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << "tmp (equiped on 1) XP is: " << tmp->getXP() << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << "tmp (equiped on 1) XP is: " << tmp->getXP() << std::endl;
		
		std::cout << std::endl;

	std::cout << BLUE << "-- Creating ICharacter \"me2\" from a copy of me " << C_RES << std::endl;
		ICharacter* me2 = new Character(*me);

	std::cout << std::endl;

	std::cout << BLUE << "-- creating ice and cure and equipping more (testing with too much) Materia --" << C_RES << std::endl;
		AMateria *cure = new Cure;
		AMateria *ice = new Ice;
		AMateria *cury = new Cure;
		AMateria *icy = new Ice;

		me2->equip(cure); //index2
		me2->equip(ice);//index3
		me2->equip(icy);//index 4 does not exist
		std::cout << "tmp (equiped on 1 from me) XP is: " << tmp->getXP() << std::endl;
		std::cout << "Cure(equiped on 2) XP is: " << cure->getXP() << std::endl;
		std::cout << "Ice (equipped on 3) XP is: " << ice->getXP() << std::endl;
		std::cout << "Icy (unequipped) XP is: " << icy->getXP() << std::endl;
		std::cout << "Cury (unequipped) XP is: " << cury->getXP() << std::endl;
	

	std::cout << std::endl;

	std::cout << BLUE << "--  use all equiped materias on ICharacter bob, deleting me then use again to prove deep copy ---- " << C_RES << std::endl;
	
		me2->use(0, *bob);
		me2->use(1, *bob);
		me2->use(2, *bob);
		me2->use(3, *bob);
		me2->use(10, *bob);
		me2->use(-1, *bob);
		std::cout << "tmp (equiped on 1 from me) XP is: " << tmp->getXP() << std::endl;

		std::cout << "Cure(equiped on 2) XP is: " << cure->getXP() << std::endl;
		std::cout << "Ice (equipped on 3) XP is: " << ice->getXP() << std::endl;
		std::cout << "Icy (unequipped) XP is: " << icy->getXP() << std::endl;
		std::cout << "Cury (unequipped) XP is: " << cury->getXP() << std::endl;
		delete me;
	std::cout << std::endl;

		me2->use(0, *bob);
		me2->use(1, *bob);
		me2->use(2, *bob);
		me2->use(3, *bob);
		me2->use(10, *bob);
		me2->use(-1, *bob);
		std::cout << "Cure(equiped on 2) XP is: " << cure->getXP() << std::endl;
		std::cout << "Ice (equipped on 3) XP is: " << ice->getXP() << std::endl;
		std::cout << "Icy (unequipped) XP is: " << icy->getXP() << std::endl;
		std::cout << "Cury (unequipped) XP is: " << cury->getXP() << std::endl;
	std::cout << std::endl;


	std::cout << BLUE << "-- Deleting bob, me2 and the MateriaSource --" << C_RES << std::endl;
		delete bob;
		delete me2;
		delete src;

	std::cout << std::endl;

	return (0);
}
