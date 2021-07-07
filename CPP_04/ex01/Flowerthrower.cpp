# include "Flowerthrower.hpp"

// Default constructor
Flowerthrower::Flowerthrower() : AWeapon("Flowerthrower", 1, 18),
			 _OutputOfAttack("-- xo peace and love xo --")
{
}

// Copy constructor
Flowerthrower::Flowerthrower(const Flowerthrower& src) : AWeapon(src)
{
}

// Destructor
Flowerthrower::~Flowerthrower(void)
{
}

// Assignation operator
Flowerthrower &	Flowerthrower::operator=(const Flowerthrower& src)
{
	AWeapon::operator=(src);
	return (*this);
}

void Flowerthrower::attack(void) const
{
	std::cout << GREEN_B << this->_OutputOfAttack << C_RES << std::endl;
	return ;
}
