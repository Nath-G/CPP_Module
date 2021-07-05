#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public virtual ISpaceMarine
{

    public:
        TacticalMarine();
        TacticalMarine(TacticalMarine const&);
        virtual ~TacticalMarine();

        TacticalMarine &operator=(const TacticalMarine &);

        TacticalMarine  *clone() const;
        void            battleCry() const;
        void            rangedAttack() const;
        void            meleeAttack() const;

};

#endif
