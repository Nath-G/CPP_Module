# include "Donkey.hpp"

// Parametric constructor (std::string
Donkey::Donkey(std::string name) : Victim(name)
{
	std::cout << GREY << "Hee Haw !" << C_RES << std::endl;
	return ;
}

// Copy constructor
Donkey::Donkey(const Donkey& src) : Victim(src)
{
	std::cout << GREY << "Copy Donkey creation..." << C_RES << std::endl;
	*this = src;
	return;
}

// Destructor
Donkey::~Donkey(void)
{
	std::cout << GREY << "arr arr arr..." << C_RES << std::endl;
	
	return;
}

// Assignation operator

Donkey &	Donkey::operator=(const Donkey& rhs)
{
	std::cout << GREY << "Donkey Assignation operator called" << C_RES << std::endl;
		this->getName() = rhs.getName();
	return (*this);
}

void		Donkey::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a pink unicorn!" << std::endl;
}
