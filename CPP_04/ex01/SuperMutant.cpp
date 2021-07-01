# include "SuperMutant.hpp"

// Default constructor
SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << ORANGE << "Gaaah. Me want smash heads!" << C_RES << std::endl;
	return ;
}

// Copy constructor
SuperMutant::SuperMutant(const SuperMutant& src) : Enemy(src)
{
	std::cout << ORANGE << "Gaaah. Me want smash heads!" << C_RES << std::endl;
	*this = src;
	return;
}

// Destructor
SuperMutant::~SuperMutant()
{
	std::cout << RED << "Aaargh..." << C_RES << std::endl;
	return;
}

// Assignation operator
SuperMutant &	SuperMutant::operator=(const SuperMutant& src)
{
	Enemy::operator=(src);
	return (*this);
}

void SuperMutant::takeDamage(int damage)
{
	this->Enemy::takeDamage(damage - 3);
	return ;
}
