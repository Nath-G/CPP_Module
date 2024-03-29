# include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &src) : AMateria(src)
{
}

Cure::~Cure()
{
}

Cure         &Cure::operator=(Cure const &rhs)
{
    AMateria::operator=(rhs);
    return (*this);
}

AMateria    *Cure::clone() const
{
    return(new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals ";
    AMateria::use(target);
    std::cout << "’s wounds *" << std::endl;
}
