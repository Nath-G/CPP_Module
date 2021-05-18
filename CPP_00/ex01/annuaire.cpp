/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annuaire.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:05:29 by nagresel          #+#    #+#             */
/*   Updated: 2021/05/18 13:53:45 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

int     choose_contact(Contact contact[8])
{
    int         choice = 0;
    std::string s;
    while (choice < 1 || choice > 8 || !contact[choice - 1].exists())
    {
        std::cout << "Please choose an available contact index: ";
        if(!(std::getline(std::cin, s)))
            choice = 0;
        choice = s[0] - 48;
    }
    return (choice - 1);
}

void    show_contact_list(Contact contact[8])
{
    int i = 0;

    std::cout << "|     index|First name| Last name| Nick name|" << std::endl;
    while (contact[i].exists() && i < 8)
    {
        contact[i].show_contact_sumup(i);
        i++;
    }
}
