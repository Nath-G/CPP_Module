#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
//# include <iterator>

template <typename T>
int easyfind(T &container, int n)
{
    typename T::const_iterator iter;

    iter = std::find(container.begin(), container.end(), n);
    if (iter == container.end())
        throw std::exception();
//    return (std::distance(container.begin(), iter));
    return (*iter);
}

#endif