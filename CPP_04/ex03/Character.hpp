#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public virtual ICharacter
{
    private:
        std::string _name;
        AMateria    *_inventory[4];
        Character();
        void        deleteInventory();
        void        copyInventory(Character const &target);

    public:
        Character(std::string const &name);
        Character(Character const &src);
        virtual ~Character();

        Character   &operator=(Character const &rhs);

        std::string const   &getName(void) const;
		void			    setName(const std::string name);
        void                equip(AMateria *m);
        void                unequip(int idx);
        void                use(int idx, ICharacter &target);

};

#endif
