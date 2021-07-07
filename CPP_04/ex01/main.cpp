# include "PlasmaRifle.hpp"
# include "PowerFist.hpp"
# include "Flamethrower.hpp"
# include "Flowerthrower.hpp"
# include "SuperMutant.hpp"
# include "RadScorpion.hpp"
# include "Piggsy.hpp"
# include "Enemy.hpp"
# include "Character.hpp"

//# include "color.hpp"

int main(void)
{
	Character* me = new Character("me");
	
	std::cout << *me;
	
	Enemy* b = new RadScorpion();
	
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	std::cout << SKY_BLUE << "----------------------------" << C_RES << std::endl;
	Enemy* c = new SuperMutant();//instance
	Enemy* d = new Piggsy();//instance
	AWeapon* fmt = new Flamethrower();//instance
	AWeapon* fwt = new Flowerthrower();//instance

	me->attack(c);
	std::cout << *me;
	me->attack(c);
	std::cout << *me;
	me->equip(pf);
	me->attack(c);
	std::cout << *me;
	me->attack(c);//pas assez de AP 
	me->recoverAP();
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	me->recoverAP();
	std::cout << *me;
	me->attack(c);
	std::cout << *me;
	me->equip(fwt);
	me->attack(c);
	std::cout << *me;
	me->attack(c);
	std::cout << *me;
	me->attack(c);
	std::cout << *me;
//	me->equip(fmt);
	me->attack(d);
	std::cout << *me;
	me->equip(fmt);
	me->attack(d);
	std::cout << *me;
	me->attack(d);
	me->equip(pr);
	me->attack(d);

	std::cout << "----------------------------" << std::endl;
		delete me;
		delete pr;
		delete pf;
		delete fmt;
		delete fwt;

	return 0;
}

