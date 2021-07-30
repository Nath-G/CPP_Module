/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:28:48 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/29 13:38:31 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

bool    is_displayable(char *str)
{
    int i = 0;
    bool is_displayable = 1;
    while(str[i] && is_displayable)
    {
        if (!(std::isprint(str[i])))
        {
            std::cout << "Error: undisplayable parameters are not allowed!" << std::endl;
            return (0);
        }
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac != 2 || av[1] == '\0')
        std::cout << "Error: bad argument." << std::endl;
    else
    {
        std::stringstream    strStrm;

        if (is_displayable(av[1]))
        {
            Converter conv(static_cast<std::string>(av[1]));
            std::cout << conv;
        }
    }
    return (0);
}