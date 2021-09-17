#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <numeric>
# include <algorithm>

class Span
{

private:
    Span(void);
    unsigned int        _size;
    std::vector<int>    _tab;


public:
    Span(unsigned int n);
    Span(Span const &src);
    virtual ~Span(void);

    Span    &operator=(Span const &rhs);
    void    addNumber(const int value);
    long    longestSpan()const;
    long    shortestSpan()const;

//    template <typename T>
//    void    addNumber(T begin, T end)
//    {

//    }
};

#endif
