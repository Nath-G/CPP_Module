# include "Victim.hpp"

// Parametric constructor (std::string
Victim::Victim(std::string name) : _name(name)
{
	std::cout << GREY << "Some random victim called "
	<< _name << " just appeared!" << C_RES << std::endl;
	return ;
}

// Copy constructor
Victim::Victim(const Victim& src)
{
	std::cout << GREY << "Copy Victim creation..." << C_RES << std::endl;
	*this = src;
	return;
}

// Destructor
Victim::~Victim(void)
{
	std::cout << GREY << "Victim " << _name
	<< " just died for no apparent reason!" << C_RES << std::endl;
	
	return;
}

// Assignation operator
Victim &	Victim::operator=(const Victim& rhs)
{
	std::cout << GREY << "Victim Assignation operator called" << C_RES << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
	}
	return (*this);
}

// getters and setters (non static attributes)
std::string Victim::getName(void) const
{
	return (this->_name);
}

void Victim::setName(const std::string name)
{
	this->_name = name;
	return ;
}

std::ostream &operator<<(std::ostream &os, const Victim & rsh)
{
	os << "I'm " << rsh.getName() << ", and I like others!" << std::endl;
	return (os);
}

void		Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}
