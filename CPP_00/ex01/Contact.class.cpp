/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:04:29 by nagresel          #+#    #+#             */
/*   Updated: 2021/05/10 16:04:29 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

Contact::Contact(void)//dans la classe annuaire j'appelle la fonction annuaire
{
    std::cout << "j'appelle le constructeur contact" << std::endl;
    return; //facultatif
}

Contact::~Contact(void)
{
    std::cout << "j'appelle le destructeur contact" << std::endl;
    return; //facultatif
}

std::string  Contact::Field_name[11]  = {
                "First name: ",
                "Last name: ",
                "Nick name: ",
                "Login :",
               "Postal address: ",
                "email address: ",
                "Phone number: ",
                "Birthday date: ",
               "Favorite meal: ",
                "Underwear color: ",
                "Darkest secret: "
        };

void    Contact::add_contact(void)
{
    int i;

    i = 0;
    while(i < 11)
    {
        std::cout << Contact::Field_name[i];
        std::getline(std::cin, Field_value[i]);
        i++;
    }
    std::cout << "oups" << std::endl;
    while (i < 22)
    {
        std::cout << Contact::Field_name[i];
        std::cout << Contact::Field_value[i];
        std::cout << std::endl;//<< Contact::Field_value[i] 
        i++;
    }
//    std::getline(std::cin, firstName);
//    std::cin.ignore();
//    std::cout << "First Name : " << Contact::Field_name[0]  << std::endl;;
    return;
}
