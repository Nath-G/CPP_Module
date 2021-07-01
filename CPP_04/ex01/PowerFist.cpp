# include "PowerFist.hpp"

// Default constructor
PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50),
			 _OutputOfAttack("* pschhh... SBAM! *")
{
}

// Copy constructor
PowerFist::PowerFist(const PowerFist& src) : AWeapon(src)
{
	return;
}

// Destructor
PowerFist::~PowerFist(void)
{
	return;
}

// Assignation operator
PowerFist &	PowerFist::operator=(const PowerFist& src)
{
	AWeapon::operator=(src);
	return (*this);
}

void PowerFist::attack(void) const
{
	std::cout << CORAIL << this->_OutputOfAttack << C_RES << std::endl;
	return ;
}
