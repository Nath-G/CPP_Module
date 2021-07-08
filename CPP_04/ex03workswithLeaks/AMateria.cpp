#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type), _xp(0)
{
}

AMateria::AMateria(AMateria const &src)
{
    *this = src;
    _type = src._type;
}

AMateria::~AMateria()
{
    return;
}

AMateria            &AMateria::operator=(const AMateria &rhs)
{
    _xp = rhs._xp;
    return (*this);
}

std::string const   &AMateria::getType() const
{
    return(_type); 
}


unsigned int        AMateria::getXP() const
{
    return (_xp);
}

void			    AMateria::setType(const std::string type)
{
    this->_type = type;
}

void                AMateria::use(ICharacter &target)
{
   std::cout << target.getName();
   unsigned int newXP = _xp + 10;
   if (newXP > _xp)
    _xp = newXP;
}
