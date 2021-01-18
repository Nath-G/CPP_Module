/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:11:40 by nagresel          #+#    #+#             */
/*   Updated: 2021/01/15 16:11:50 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
    if (ac <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];
        for (size_t j = 0; j < str.size(); j++)
            str.at(j) = std::toupper(str.at(j));
       std::cout << str;
    }
    std::cout << std::endl;
	return (0);
}