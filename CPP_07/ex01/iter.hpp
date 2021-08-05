#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void    display(T const &x)
{
    std::cout << "<" << x << ">" << std::endl;
}

template <typename T>
void iter(T *array, size_t len, void(*f)(T const &))
{
    if(!array)
        return;
    for (size_t i = 0; i < len; i++)
    {
        f(array[i]);
    }
    return;
}




#endif
