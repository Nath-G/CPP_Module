#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

typedef struct	s_data {
    uintptr_t       address;
    char        *str_1;
    char        *str_2;
    int         n;
    }			Data;

#endif