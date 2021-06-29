# include "Character.hpp"

// Default constructor
Character::Character(void)
{
	std::cout << GREY << "Character creation..." << C_RES << std::endl;
	this->_name = "What ever";
	this->_ap = 40;
	this-> _weapon = NULL;
	return ;
}

// Parametric constructor (std::string &)
Character::Character(const std::string & name) : _name(name), _ap(40), _weapon(NULL)
{
	std::cout << GREY << "Character creation..." << C_RES << std::endl;
	return ;
}

// Copy constructor
Character::Character(const Character& src)
{
	std::cout << GREY << "Character creation..." << C_RES << std::endl;
	*this = src;
	return;
}

// Destructor
Character::~Character(void)
{
	std::cout << GREY << "Character destruction..." << C_RES << std::endl;
	return;
}

// Assignation operator
Character &	Character::operator=(const Character& rhs)
{
	std::cout << GREY << "Character Assignation operator called" << C_RES << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_ap = rhs.getAP();
		this->_weapon = rhs.getWeapon();
	}
	return (*this);
}

// getters and setters (non static attributes)
std::string Character::getName(void) const
{
	return (this->_name);
}

void Character::setName(const std::string name)
{
	this->_name = name;
	return ;
}

int Character::getAP(void) const
{
	return (this->_ap);
}

void Character::setAP(const int AP)
{
	this->_ap = AP;
	return ;
}

AWeapon			*Character::getWeapon() const
{
	return (_weapon);
}

void Character::recoverAP()
{
	std::cout << GREY << "recoverAP called" << C_RES << std::endl;
	return ;
}

void Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
	return ;
}

void Character::attack(Enemy *target)
{
	if (!target)
	{
		std::cout << *this << std::endl;
		return;
	}
	else if (!_weapon)
		return;
	else if (_ap < _weapon->getAPCost())
		return;
	else if (!target->getHP())
	{
		std::cout << YELLOW << *this << std::endl;
		return;
	}
	std::cout << CYAN << _name << " attacks " << target->getType() << " with a " << *_weapon << C_RES << std::endl;
	_weapon->attack();
	target->takeDamage(_weapon->getDamage());
	_ap = _ap - _weapon->getAPCost();
	std::cout << _name << " action points amount is " << _ap << std::endl;//A ENLEVER
	if (!target->getHP())
	{
		target = NULL;
		delete(target);
	}
	return ;
}

// overload de <<
std::ostream &operator<<(std::ostream &os, const Character & src)
{
	if(src.getWeapon())
		os << YELLOW << src.getName() << " has " << src.getAP() << " AP and wields a " << src.getWeapon()->getName() << C_RES << std::endl;
	else
		os << YELLOW << src.getName() << " has " << src.getAP() <<  " AP and is unarmed" << C_RES << std::endl;
	return (os);
}

