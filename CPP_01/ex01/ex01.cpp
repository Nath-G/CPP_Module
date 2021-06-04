/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:48:32 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/04 16:53:20 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void    memory_leak()
{
    std::string*    panthere = new std::string("new string panthere");

    std::cout << *panthere << std::endl;

    delete panthere;
}

int     main()
{
    memory_leak();
}