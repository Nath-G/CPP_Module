#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        _source[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
   *this = src;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
      //  if (_source[i] != NULL)
        {
            delete _source[i];
        //    this->_source[i] = NULL;
        }
    }
}

MateriaSource   &MateriaSource::operator=(MateriaSource const &rhs)
{
   deleteSource();
   copySource(rhs);
   return(*this);
}

void        MateriaSource::deleteSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_source[i] != NULL)
        {
            delete _source[i];
            this->_source[i] = NULL;
        }
    }
}

void        MateriaSource::copySource(MateriaSource const &target)
{
    for (int i = 0; i < 4; i++)
    {
        this->_source[i] = NULL;
        if (target._source[i])
            this->_source[i] = target._source[i]->clone();
    }
}

void            MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;

	int i;

	for (i = 0; i < 4 && _source[i]; i++);
	if (i < 4)
		_source[i] = m;
	return;
    /*if (!m)
        return;
    int i = 0;
	while (i < 4)
	{
		if (this->_learn[i] == NULL)
		{
			this->_learn[i] = m;
			break;
		}
		i++;
	}*/
}

AMateria       *MateriaSource::createMateria(std::string const &type)
{
   for (int i = 0; i < 4 ; i++)
	{
		if (_source[i] && _source[i]->getType() == type)
			return(_source[i]->clone());
	}

   /* for (int i = 0; i < 4 ; i++)
	{
        if (_learn[i] && _learn[i]->getType() == type)
        {
          for (int j = 0; j < 4 ; j++)
           {
                if (_source[j] == NULL)
                {
                    _source[j] = _learn[i]->clone();
                    return(_source[i]);
                }
           }
        }
	}*/
    return(0);
}
