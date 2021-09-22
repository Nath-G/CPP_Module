#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <numeric>
# include <algorithm>
# include <iterator>


class Span
{

private:
    Span(void);
    unsigned int        _size;
    std::vector<int>    _board;


public:
    Span(unsigned int n);
    Span(Span const &src);
    virtual ~Span(void);

    Span    &operator=(Span const &rhs);
    void    addNumber(const int value);
    void 	display_board();

    unsigned int    longestSpan()const;
    unsigned int    shortestSpan()const;

    template <typename T>
    void    addNumber(T begin, T end)
    {
        if (static_cast<unsigned long>(std::distance(begin, end)) > (_size - this->_board.size()))
            throw(std::runtime_error("Tab is full!"));
        this->_board.insert(this->_board.begin(), begin, end);
    }
};

#endif
