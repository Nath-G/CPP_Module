#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public virtual ISquad
{

    private:
        typedef struct         s_unit
        {
            ISpaceMarine    *unit;
            struct  s_unit  *next;
        }                   t_unit;
        int                 _unitCount;
        t_unit              *_unitPtr;

        void    destroy_units(t_unit *ptr);
        void    copy_units(t_unit *src);

    public:
        Squad();
        Squad(Squad const &src);
        virtual ~Squad();

        Squad &operator=(Squad const &rsh);

        int             getCount() const;
        ISpaceMarine    *getUnit(int) const;
        int             push(ISpaceMarine*);
};

#endif
