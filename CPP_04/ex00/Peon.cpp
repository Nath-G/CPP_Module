# include "Peon.hpp"

// Parametric constructor (std::string
Peon::Peon(std::string name) : Victim(name)
{
	std::cout << GREY << "Zog zog." << C_RES << std::endl;
	return ;
}

// Copy constructor
Peon::Peon(const Peon& src) : Victim(src)
{
	std::cout << GREY << "Copy Peon creation..." << C_RES << std::endl;
	*this = src;
	return;
}

// Destructor
Peon::~Peon(void)
{
	std::cout << GREY << "Bleuark..." << C_RES << std::endl;
	
	return;
}

// Assignation operator

Peon &	Peon::operator=(const Peon& rhs)
{
	std::cout << GREY << "Peon Assignation operator called" << C_RES << std::endl;
		this->getName() = rhs.getName();
	return (*this);
}

void		Peon::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}
