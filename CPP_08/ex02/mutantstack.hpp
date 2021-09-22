#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <iterator>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::deque<T>::iterator iterator;

    MutantStack() : std::stack<T>() {};
    MutantStack(MutantStack &src) : std::stack<T>() {*this = src;};
    virtual ~MutantStack() {};

    MutantStack     &operator =(MutantStack &rhs) {std::stack<T>::operator=(rhs); return *this;};

    iterator    begin() {return(this->c.begin());};
    iterator    end() {return(this->c.end());};
};
#endif
