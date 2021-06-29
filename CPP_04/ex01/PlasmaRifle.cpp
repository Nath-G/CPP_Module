# include "PlasmaRifle.hpp"

// Default constructor
PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21),
			 _OutputOfAttack("* piouuu piouuu piouuu *")
{
	std::cout << GREY << _name << " creation..." << C_RES << std::endl;
	return ;
}

// Copy constructor
PlasmaRifle::PlasmaRifle(const PlasmaRifle& src) : AWeapon(src)
{
	std::cout << GREY  << _name << " copy creation..." << C_RES << std::endl;
	return;
}

// Destructor
PlasmaRifle::~PlasmaRifle(void)
{
	std::cout << GREY << _name << " destruction..." << C_RES << std::endl;
	return;
}

// Assignation operator
PlasmaRifle &	PlasmaRifle::operator=(const PlasmaRifle& rhs)
{
	AWeapon::operator=(rhs);
	return (*this);
}

void PlasmaRifle::attack(void) const
{
	std::cout << CORAIL << this->_OutputOfAttack << C_RES << std::endl;
	return ;
}
