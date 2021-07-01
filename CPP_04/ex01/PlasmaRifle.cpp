# include "PlasmaRifle.hpp"

// Default constructor
PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21),
			 _OutputOfAttack("* piouuu piouuu piouuu *")
{
}

// Copy constructor
PlasmaRifle::PlasmaRifle(const PlasmaRifle& src) : AWeapon(src)
{
}

// Destructor
PlasmaRifle::~PlasmaRifle(void)
{
}

// Assignation operator
PlasmaRifle &	PlasmaRifle::operator=(const PlasmaRifle& src)
{
	AWeapon::operator=(src);
	return (*this);
}

void PlasmaRifle::attack(void) const
{
	std::cout << CORAIL << this->_OutputOfAttack << C_RES << std::endl;
	return ;
}
