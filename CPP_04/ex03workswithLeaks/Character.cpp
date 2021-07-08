#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
}

Character::Character(Character const &src)
{
    this->deleteInventory();
    this->_name = src._name;
}

Character::~Character()
{
    this->deleteInventory();
}

Character       &Character::operator=(Character const &rhs)
{
    this->deleteInventory();
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

void        Character::deleteInventory()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] != NULL)
        {
            this->_inventory[i] = NULL;
            delete _inventory[i];
        }
    }
}

void        Character::copyInventory(Character const &target)
{
    for (int i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
        if (target._inventory[i])
            this->_inventory[i] = target._inventory[i]->clone();
    }
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
