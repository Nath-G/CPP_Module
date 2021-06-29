# include "PowerFist.hpp"

// Default constructor
PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50),
			 _OutputOfAttack("* pschhh... SBAM! *")
{
	std::cout << GREY << _name << " creation..." << C_RES << std::endl;
	return ;
}

// Copy constructor
PowerFist::PowerFist(const PowerFist& src) : AWeapon(src)
{
	std::cout << GREY  << _name << " copy creation..." << C_RES << std::endl;
	return;
}

// Destructor
PowerFist::~PowerFist(void)
{
	std::cout << GREY << _name << " destruction..." << C_RES << std::endl;
	return;
}

// Assignation operator
PowerFist &	PowerFist::operator=(const PowerFist& rhs)
{
	AWeapon::operator=(rhs);
	return (*this);
}

void PowerFist::attack(void) const
{
	std::cout << CORAIL << this->_OutputOfAttack << C_RES << std::endl;
	return ;
}
