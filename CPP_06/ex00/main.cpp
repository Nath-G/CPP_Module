/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:28:48 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/26 15:34:47 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int main(int ac, char **av)
{
    if (ac != 2 || av[1] == '\0')
    {
        std::cout << "Error: bad argument." << std::endl;

    }
    else
    {
        Converter conv(av[1]);
        std::cout << conv;
    }
    return (0);
}