#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
#include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    private:
        std::string     _type;
        unsigned int    _xp;
        AMateria();

    
    public:
        AMateria(std::string const & type);
        AMateria(AMateria const &src);
        virtual ~AMateria();

        AMateria &operator=(AMateria const &rhs);

        std::string const & getType() const; //Returns the materia type
        unsigned int getXP() const; //Returns the Materia's XP
        void                setType(const std::string type);

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);

};

#endif
