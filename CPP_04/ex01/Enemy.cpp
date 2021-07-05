# include "Enemy.hpp"

// Parametric constructor (std::string)
Enemy::Enemy(int hp, std::string type) : _hp(hp), _type(type)
{
	return ;
}

// Copy constructor
Enemy::Enemy(const Enemy& src)
{
	*this = src;
	return;
}

// Destructor
Enemy::~Enemy(void)
{
}

// Assignation operator
Enemy &	Enemy::operator=(const Enemy& src)
{
//	std::cout << GREY << "Enemy Assignation operator called" << C_RES << std::endl;
	if (this != &src)
	{
		this->_hp = src.getHP();
		this->_type = src.getType();
	}
	return (*this);
}

// getters and setters (non static attributes)
int Enemy::getHP(void) const
{
	return (this->_hp);
}

void Enemy::setHP(const int hp)
{
	this->_hp = hp;
	return ;
}

std::string Enemy::getType(void) const
{
	return (this->_type);
}

void Enemy::setType(const std::string type)
{
	this->_type = type;
	return ;
}

void Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return;
	_hp = (damage < _hp) ? (_hp - damage) : 0;
	return ;
}

// overload de <<
std::ostream &operator<<(std::ostream &os, const Enemy & src)
{
	os << src.getHP();
	return (os);
}
