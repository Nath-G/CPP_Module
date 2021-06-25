# include "Sorcerer.hpp"

// Default constructor
Sorcerer::Sorcerer(void)
{
	std::cout << GREY << "Sorcerer creation..." << C_RES << std::endl;
	return ;
	
}

// Parametric constructor (std::string)
Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << GREY << _name << ", " << _title << " is born!" << C_RES << std::endl;
	return ;
}

// Copy constructor
Sorcerer::Sorcerer(const Sorcerer& src)
{
	std::cout << GREY << "Copy Sorcerer creation..." << C_RES << std::endl;
	*this = src;
	return;
}

// Destructor
Sorcerer::~Sorcerer(void)
{
	std::cout << GREY << _name << ", " << _title
	<< ", is dead. Consequences will never be the same!" << C_RES << std::endl;
	return;
}

// Assignation operator
Sorcerer &	Sorcerer::operator=(const Sorcerer& rhs)
{
	std::cout << GREY << "Sorcerer Assignation operator called" << C_RES << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_title = rhs.getTitle();
	}
	return (*this);
}

// getters and setters (non static attributes)
std::string Sorcerer::getName(void) const
{
	return (this->_name);
}

void Sorcerer::setName(const std::string name)
{
	this->_name = name;
	return ;
}

std::string Sorcerer::getTitle(void) const
{
	return (this->_title);
}

void Sorcerer::setTitle(const std::string title)
{
	this->_title = title;
	return ;
}

// overload de <<
std::ostream &operator<<(std::ostream &os, const Sorcerer & rsh)
{
	os << "I am " << rsh.getName() << ", " << rsh.getTitle() << ", and I like ponies!" << std::endl;
	return (os);
}

/*
void	Sorcerer::polymorph(const Victim &target)const
{
	target.getPolymorphed();
}
*/
