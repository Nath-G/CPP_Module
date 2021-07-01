# include "Piggsy.hpp"

// Default constructor
Piggsy::Piggsy() : Enemy(51, "Piggsy")
{
	std::cout << ORANGE << "* oink-oink *" << C_RES << std::endl;
	return ;
}

// Copy constructor
Piggsy::Piggsy(const Piggsy& src) : Enemy(src)
{
	std::cout << ORANGE << "* oink-oink *" << C_RES << std::endl;
	*this = src;
	return ;
}

// Destructor
Piggsy::~Piggsy()
{
	std::cout << RED <<  "* wee-wee *" << C_RES << std::endl;
	return;
}

// Assignation operator
Piggsy &	Piggsy::operator=(const Piggsy& src)
{
	Enemy::operator=(src);
	return (*this);
}
