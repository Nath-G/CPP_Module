#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public virtual IMateriaSource
{
    private:
        AMateria    *_learn[4];
        AMateria    *_source[4];
        void        deleteSource();
        void        copySource(MateriaSource const &target);
        

    public:
        MateriaSource();
        MateriaSource(MateriaSource const &src);
        virtual ~MateriaSource();

        MateriaSource &operator=(MateriaSource const &rhs);

        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
};

#endif
