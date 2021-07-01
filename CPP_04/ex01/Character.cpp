# include "Character.hpp"

// Parametric constructor (std::string &)
Character::Character(const std::string & name) : _name(name), _ap(40), _weapon(NULL)
{
}

// Copy constructor
Character::Character(const Character& src)
{
	*this = src;
	return;
}

// Destructor
Character::~Character(void)
{
}

// Assignation operator
Character &	Character::operator=(const Character& src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_ap = src.getAP();
		this->_weapon = src.getWeapon();
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
	if (_ap < 40)
		_ap += 10;
	_ap = (_ap > 40) ? 40 : _ap;
	return;
}

void Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
	return ;
}

void Character::attack(Enemy *target)
{
	if (!(target->getHP()) || !target)
	{
		std::cout << *this << std::endl;
		return;
	}
	else if (!_weapon)
		return;
	else if ( _weapon->getAPCost() &&_ap < _weapon->getAPCost())
	{
		std::cout << GREY << _name << " has not enought Action Points to use " << _weapon->getName() << C_RES << std::endl;
		return;

	}
	std::cout << YELLOW << _name << " attacks " << target->getType() << " with a "
	<< *_weapon << C_RES << std::endl;
	_weapon->attack();
	target->takeDamage(_weapon->getDamage());
	_ap = _ap - _weapon->getAPCost();
	if (!(target->getHP()))
	{
		delete target;
		return;
	}
	return ;
}

// overload de <<
std::ostream &operator<<(std::ostream &os, const Character & src)
{
	if(src.getWeapon())
		os << BLUE << src.getName() << " has " << src.getAP() << " AP and wields a " << src.getWeapon()->getName() << C_RES << std::endl;
	else
		os << GREEN_B << src.getName() << " has " << src.getAP() <<  " AP and is unarmed" << C_RES << std::endl;
	return (os);
}

