#include "span.hpp"

Span::Span(unsigned int n) : _size(n)
{
    this->_board.reserve(n);
}

Span::Span(Span const &src) : _size(src._size)
{
    this->_board = src._board;
}

Span::~Span()
{
}

Span    &Span::operator=(Span const &rhs)
{
    this->_board = rhs._board;
    this->_size = rhs._size;
    return(*this);
}

void    Span::addNumber(const int value)
{
    if (this->_board.size() < _size)
        this->_board.push_back(value);
    else
        throw(std::runtime_error("Board is full!"));
    return;
}

static void display_int(int n){ std::cout << n << " "; }

void 	Span::display_board()
{
	std::for_each(this->_board.begin(), this->_board.end(), &display_int);
	std::cout << std::endl;
}

unsigned int    Span::longestSpan()const
{
    if (this->_board.size() < 2)
        throw(std::runtime_error("At least 2 numbers are required!"));
    int min = *std::min_element(this->_board.begin(), this->_board.end());
    int max = *std::max_element(this->_board.begin(), this->_board.end());
    return(max - min);
}

unsigned int    Span::shortestSpan()const
{
    if (this->_board.size() < 2)
        throw(std::runtime_error("At least 2 numbers are required!"));
    int n = this->_board.size();
    std::vector<int> t = this->_board;
    std::vector<unsigned int> result(n);
    std::sort(t.begin(), t.end());
    std::adjacent_difference(t.begin(), t.end(),result.begin());
    return *std::min_element(result.begin() + 1, result.end());
}
