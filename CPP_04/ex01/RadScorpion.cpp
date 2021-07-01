# include "RadScorpion.hpp"

// Default constructor
RadScorpion::RadScorpion() : Enemy(80, "Rad Scorpion")
{
	std::cout << ORANGE << "* click click click *" << C_RES << std::endl;
	return ;
}

// Copy constructor
RadScorpion::RadScorpion(const RadScorpion& src) : Enemy(src)
{
	std::cout << ORANGE << "* click click click *" << C_RES << std::endl;
	*this = src;
	return ;
}

// Destructor
RadScorpion::~RadScorpion()
{
	std::cout << RED <<  "* SPROTCH *" << C_RES << std::endl;
	return;
}

// Assignation operator
RadScorpion &	RadScorpion::operator=(const RadScorpion& src)
{
	Enemy::operator=(src);
	return (*this);
}
