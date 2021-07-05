#include "Squad.hpp"

Squad::Squad() : _unitCount(0), _unitPtr(NULL)
{
}

Squad::Squad(Squad const &src) : _unitCount(0), _unitPtr(NULL)
{
    *this = src;
}

Squad::~Squad()
{
    destroy_units(this->_unitPtr);
}

Squad   &Squad::operator=(Squad const &rsh)
{
    if (this == &rsh)
        return (*this);
    this->_unitCount = 0 ;
    this->destroy_units(this->_unitPtr);
    copy_units(rsh._unitPtr);
    return (*this);
}

int             Squad::getCount() const
{
    return (_unitCount);
}

ISpaceMarine    *Squad::getUnit(int n) const
{

    if (n >= getCount() || n < 0)
        return (NULL);
    t_unit *cur;
    cur = _unitPtr;
    while (n--)
        cur = cur->next;
    return (cur->unit);
}

int     Squad::push(ISpaceMarine *target)
{
    t_unit *cur;

    if(target == NULL)
    {
        std::cout << "Error: add a NUll Pointer is not possible! " << std::endl;
        return (-1);
    }

    if (!_unitPtr)
    {
        _unitPtr = new t_unit;
        _unitPtr->unit = target;
        _unitPtr->next = NULL;
        return (++_unitCount);
    }
    cur = this->_unitPtr;
    while (cur != NULL)
    {
        if (cur->unit == target)
        {
            std::cout << "Error: this Marine already exits! not possible to add it twice! " << std::endl;
            return (-1);
        }
        if (cur->next == NULL)
            break;
        cur = cur->next;
    }
    cur->next = new t_unit;
    cur = cur->next;
    cur->unit = target;
    cur->next = NULL;
    return(++_unitCount);
}

void    Squad::destroy_units(t_unit *ptr)
{
    if (ptr == NULL)
        return;
    destroy_units(ptr->next);
    delete ptr->unit;
    delete ptr;

}

void    Squad::copy_units(t_unit *src)
{
    t_unit  *cur;

    cur = src;
    while (cur)
    {
        this->push(cur->unit->clone());
        cur = cur->next;
    }
}
