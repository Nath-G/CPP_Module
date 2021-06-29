# include "SuperMutant.hpp"

// Default constructor
SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << GREY << "Gaaah. Me want smash heads!" << C_RES << std::endl;
	return ;
}

// Copy constructor
SuperMutant::SuperMutant(const SuperMutant& src) : Enemy(src)
{
	std::cout << GREY << "Gaaah. Me want smash heads!" << C_RES << std::endl;
	*this = src;
	return;
}

// Destructor
SuperMutant::~SuperMutant()
{
	std::cout << GREY << "Aaargh..." << C_RES << std::endl;
	return;
}

// Assignation operator
SuperMutant &	SuperMutant::operator=(const SuperMutant& rhs)
{
	Enemy::operator=(rhs);
	std::cout << GREY << "SuperMutant Assignation operator called" << C_RES << std::endl;
	/*if (this != &rhs)
	{
		this->_hp = rhs.getHp();
		this->_type = rhs.getType();
	}*/
	return (*this);
}

void SuperMutant::takeDamage(int damage)
{
	this->Enemy::takeDamage(damage - 3);
	/*unsigned int is_alive = 1;

	if (_hp == 0)
		is_alive = 0;
	_hp = ((damage - 3) < _hp) ? (_hp - (damage - 3)) : 0;
	if (is_alive == 1)
		std::cout << GREY << _type << " loses " << damage - 3 << " hit points (3pts less than normal)! So its hit points amount is now: " << _hp << C_RES << std::endl;
	*/
	return ;
}

