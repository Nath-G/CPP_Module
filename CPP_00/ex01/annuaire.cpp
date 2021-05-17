/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annuaire.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:05:29 by nagresel          #+#    #+#             */
/*   Updated: 2021/05/17 14:13:13 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

int     choose_contact(void)
{
    int c;
    std::cout << "Please choose the contact index you want to display : ";
    std::cin >> c;
    std::cin.ignore();
    return (c);
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

void    search_contact(Contact contact[8])
{
    int c;
    show_contact_list(contact);
    c = choose_contact();
    contact[c - 1].show_contact();
}