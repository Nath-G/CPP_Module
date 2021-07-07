#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(Character const &src)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    *this = src;
}

Character::~Character()
{
     for (int i = 0; i < 4; i++)
        delete _inventory[i];
}

Character       &Character::operator=(Character const &rhs)
{
    for (int i = 0; i < 4; i++)
        delete _inventory[i];

   for (int i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
        if (rhs._inventory[i])
            this->_inventory[i] = rhs._inventory[i]->clone();
    }
    _name = rhs._name;
   
    return(*this);
}

std::string const   &Character::getName(void) const
{
    return (this->_name);
}

void			    Character::setName(const std::string name)
{
    this->_name = name;
}

void        Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
     //   if (this->_inventory[i] == m)
	 //       return ;
	}
}

void        Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    if (_inventory[idx])
        this->_inventory[idx] = NULL;
}

void        Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3 || _inventory[idx] == 0)
        return ;
    if (_inventory[idx])
       this->_inventory[idx]->use(target);
    return;
}
