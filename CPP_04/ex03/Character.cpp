#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    for (int i = 0; i < 10; i++)
        this->_oldMateria[i] = NULL;
}

Character::Character(Character const &src)
{
  
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    for (int i = 0; i < 10; i++)
        this->_oldMateria[i] = NULL;
    for (int i = 0; i < 4; i ++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
    for(int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
}

Character::~Character()
{
     for (int i = 0; i < 4; i++)
        delete _inventory[i];     
    for (int i = 0; i < 10; i++)
        delete _oldMateria[i];
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
    for (int i = 0; i < 10; i++)
        delete _oldMateria[i];
    for (int i = 0; i < 10; i++)
    {
        this->_oldMateria[i] = NULL;
        if (rhs._oldMateria[i])
            this->_oldMateria[i] = rhs._oldMateria[i]->clone();
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
			removeFromOldMateriaOldMateria(m);
            this->_inventory[i] = m;
			return;
		}
    //    if (this->_inventory[i] == m)
	//        return ;
	}
    addToOldMateria(m);
}

void        Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    if (_inventory[idx])
    {
        addToOldMateria(_inventory[idx]);
        this->_inventory[idx] = NULL;
    }
}

void        Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 3 || _inventory[idx] == 0)
        return ;
    if (_inventory[idx])
       this->_inventory[idx]->use(target);
    return;
}

void        Character::addToOldMateria(AMateria *target)
{
    for (int i = 0; i < 10; i++)
    {
        if (_oldMateria[i] && target == _oldMateria[i])
            return;
        if (_oldMateria[i] == NULL)
        {
            _oldMateria[i] = target;
            return;
        }
    }
    return;
}
void        Character::removeFromOldMateriaOldMateria(AMateria *target)
{
    for (int i = 0; i < 10; i++)
    {
        if (_oldMateria[i] == target)
        {
            _oldMateria[i] = NULL;
            {
                while (i < 10 && _oldMateria[i + 1] != NULL)
                {
                    _oldMateria[i] = _oldMateria[i + 1];
                    _oldMateria[i + 1] = NULL;
                    i++;
                }
            }
        }
    }
}
