# include "Enemy.hpp"

// Default constructor
Enemy::Enemy(void)
{
	std::cout << GREY << "Enemy creation..." << C_RES << std::endl;
	return ;
}

// Parametric constructor (std::string)
Enemy::Enemy(int hp, std::string type) : _hp(hp), _type(type)
{
	std::cout << GREY << "Enemy creation..." << C_RES << std::endl;
	return ;
}

// Copy constructor
Enemy::Enemy(const Enemy& src)
{
	std::cout << GREY << "Enemy creation..." << C_RES << std::endl;
	*this = src;
	return;
}

// Destructor
Enemy::~Enemy(void)
{
	return;
}

// Assignation operator
Enemy &	Enemy::operator=(const Enemy& rhs)
{
	std::cout << GREY << "Enemy Assignation operator called" << C_RES << std::endl;
	if (this != &rhs)
	{
		this->_hp = rhs.getHP();
		this->_type = rhs.getType();
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
    unsigned int is_alive = 1;

	if (_hp == 0)
		is_alive = 0;
	_hp = (damage < _hp) ? (_hp - damage) : 0;
	if (is_alive == 1)
		std::cout << GREY << _type << " loses " << damage << " hit points! So its hit points amount is now: " << _hp << C_RES << std::endl;
	return ;
}

// overload de <<
std::ostream &operator<<(std::ostream &os, const Enemy & src)
{
	os << src.getHP();
	return (os);
}
