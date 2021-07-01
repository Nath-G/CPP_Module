# include "Flamethrower.hpp"

// Default constructor
Flamethrower::Flamethrower() : AWeapon("Flamethrower", 3, 15),
			 _OutputOfAttack("* pffff pffff pffff *")
{
}

// Copy constructor
Flamethrower::Flamethrower(const Flamethrower& src) : AWeapon(src)
{
}

// Destructor
Flamethrower::~Flamethrower(void)
{
}

// Assignation operator
Flamethrower &	Flamethrower::operator=(const Flamethrower& src)
{
	AWeapon::operator=(src);
	return (*this);
}

void Flamethrower::attack(void) const
{
	std::cout << CORAIL << this->_OutputOfAttack << C_RES << std::endl;
	return ;
}
