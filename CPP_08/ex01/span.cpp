#include "span.hpp"

Span::Span(unsigned int n) : _size(n)
{
    this->_tab.reserve(n);
}

Span::Span(Span const &src) : _size(src._size)
{
    this->_tab = src._tab;
}

Span::~Span()
{
}

Span    &Span::operator=(Span const &rhs)
{
    this->_tab = rhs._tab;
    this->_size = rhs._size;
    return(*this);
}

void    Span::addNumber(const int value)
{
    if (this->_tab.size() < _size)
        this->_tab.push_back(value);
    else
        throw(std::runtime_error("Tab is full!"));
    return;
}

long    Span::longestSpan()const
{
    if (this->_tab.size() < 2)
        throw(std::runtime_error("No enough elements in the tab!"));

    int min = *std::min_element(this->_tab.begin(), this->_tab.end());
    int max = *std::max_element(this->_tab.begin(), this->_tab.end());
    return(max - min);
}

long    Span::shortestSpan()const
{
    if (this->_tab.size() < 2)
        throw(std::runtime_error("No enough elements in the tab!"));

    std::vector<int> t = this->_tab;
    std::sort(t.begin(), t.end());
    std::adjacent_difference(t.begin(), t.end(), t.begin());
    return(*std::min_element(this->_tab.begin(), this->_tab.end()));
 //   return;
}
