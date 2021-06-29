# include "RadScorpion.hpp"

// Default constructor
RadScorpion::RadScorpion() : Enemy(80, "Rad Scorpion")
{
	std::cout << GREY << "* click click click *" << C_RES << std::endl;
	return ;
}

// Copy constructor
RadScorpion::RadScorpion(const RadScorpion& src) : Enemy(src)
{
	std::cout << GREY << "* click click click *" << C_RES << std::endl;
	*this = src;
	return;
}

// Destructor
RadScorpion::~RadScorpion()
{
	std::cout << GREY << "* SPROTCH *" << C_RES << std::endl;
	return;
}

// Assignation operator
RadScorpion &	RadScorpion::operator=(const RadScorpion& rhs)
{
	Enemy::operator=(rhs);
	std::cout << GREY << "RadScorpion Assignation operator called" << C_RES << std::endl;
	/*if (this != &rhs)
	{
		this->_hp = rhs.getHp();
		this->_type = rhs.getType();
	}*/
	return (*this);
}
/*
void RadScorpion::takeDamage(int damage)
{
	unsigned int is_alive = 1;

	if (_hp == 0)
		is_alive = 0;
	_hp = ((damage - 3) < _hp) ? (_hp - (damage - 3)) : 0;
	if (is_alive == 1)
		std::cout << BLUE << _type << " loses " << damage - 3 << " hit points (3pts less than normal)! So its hit points amount is now: " << _hp << C_RES << std::endl;
	return ;
}*/

