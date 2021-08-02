/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:28:48 by nagresel          #+#    #+#             */
/*   Updated: 2021/08/02 11:50:53 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int main(int ac, char **av)
{
    if (ac != 2 || av[1] == '\0')
        std::cout << "Error: bad argument." << std::endl;
    else
    {
        Converter conv(static_cast<std::string>(av[1]));
        std::cout << conv;
    }
    return (0);
}
