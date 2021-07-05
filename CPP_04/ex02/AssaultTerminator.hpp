#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public virtual ISpaceMarine
{

    public:
        AssaultTerminator();
        AssaultTerminator(AssaultTerminator const&);
        virtual ~AssaultTerminator();

        AssaultTerminator &operator=(const AssaultTerminator &);

        AssaultTerminator  *clone() const;
        void            battleCry() const;
        void            rangedAttack() const;
        void            meleeAttack() const;

};

#endif
