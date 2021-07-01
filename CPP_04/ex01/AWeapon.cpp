# include "AWeapon.hpp"

// Parametric constructor (std::string &)
AWeapon::AWeapon(std::string const & name, int apcost, int damage) : _name(name), _apcost(apcost), _damage(damage)
{
	return ;
}

// Copy constructor
 AWeapon::AWeapon(const  AWeapon& src)
{
	std::cout << GREY << "AWeapon creation..." << C_RES << std::endl;
	*this = src;
	return;
}

// Destructor
 AWeapon::~AWeapon(void)
{
	return;
}

// Assignation operator
 AWeapon &	AWeapon::operator=(const  AWeapon& rhs)
{
	std::cout << GREY << "AWeapon Assignation operator called" << C_RES << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_apcost = rhs.getAPCost();
		this->_damage = rhs.getDamage();
	}
	return (*this);
}

// getters and setters (non static attributes)
std::string AWeapon::getName(void) const
{
	return (this->_name);
}

void AWeapon::setName(const std::string name)
{
	this->_name = name;
	return ;
}

int AWeapon::getAPCost(void) const
{
	return (this->_apcost);
}

void AWeapon::setAPCost(const int apcost)
{
	this->_apcost = apcost;
	return ;
}

int AWeapon::getDamage(void) const
{
	return (this->_damage);
}

void AWeapon::setDamage(const int damage)
{
	this->_damage = damage;
	return ;
}

// overload de <<
std::ostream &operator<<(std::ostream &os, const AWeapon & src)
{
	os << src.getName();
	return (os);
}
