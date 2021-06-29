# include "PlasmaRifle.hpp"
# include "PowerFist.hpp"
# include "SuperMutant.hpp"
# include "RadScorpion.hpp"
# include "Enemy.hpp"
# include "Character.hpp"

# include "color.hpp"

int main(void)
{
	std::cout << ORANGE  << "*** Constructeurs instanciés sur le tas (allocations)... ***" << C_RES << std::endl;
	AWeapon		*pRifle = new PlasmaRifle();
	AWeapon		*pFist = new PowerFist();
	Enemy		*sMutant = new SuperMutant();
	RadScorpion		*rScorpion = new RadScorpion();
	RadScorpion		*rScorpion2 = new RadScorpion();

	Character	*ca = new Character("Malabar");
	std::cout << *ca << std::endl;

	std::cout << ORANGE  << "*** Constructeurs instanciés sur la pile... ***" << C_RES << std::endl;
	PlasmaRifle plasmaR;// 
	PowerFist	powerR;
	SuperMutant	superM;
	RadScorpion	radS;
//	std::string	nom = "oo";
//	Character	car(nom);

	std::cout << ORANGE << std::endl << "*** Attaques instances du tas ***" << std::endl;


	ca->attack(sMutant);
	//config...
	ca->equip(pFist);
	std::cout << *ca << std::endl;

	ca->attack(sMutant);
	ca->attack(rScorpion);
	ca->attack(rScorpion);
	ca->attack(rScorpion2);
	

	std::cout << ORANGE << std::endl << "*** Attaques instances de la pile ***" << std::endl;
//	plasmaR.attack();
//	powerR.attack();

	ca->equip(&plasmaR);

	ca->attack(&radS);
	ca->equip(&powerR);
	ca->attack(rScorpion);
	ca->attack(rScorpion);
	ca->attack(rScorpion);

// std::cout << "ca is " << *ca << std::endl;
//	superM.takeDamage(plasmaR.damage);
//	superM.takeDamage(146);
//	superM.takeDamage(14);
//	radS.takeDamage(30);
//	radS.takeDamage(50);
//	radS.takeDamage(14);
	
	std::cout << "-------------------------" << std::endl;
	std::cout << ORANGE  << "*** Destructeurs instanciés sur le tas (allocations)... ***" << C_RES << std::endl;

	if (pRifle)
		delete(pRifle);
	if(pFist)
		delete(pFist);
	if(sMutant->getHP())
		delete(sMutant);
	if (rScorpion->getHP())
		delete(rScorpion);
	if (ca)
		delete(ca);
//
	std::cout << ORANGE  << "*** Destructeurs instanciés sur la pile... ***" << C_RES << std::endl;

	return 0;
}

