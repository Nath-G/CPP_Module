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

bool        Contact::exists(void)
{
    return (Field_value[0] != "");
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

void    Contact::display_contact(int i)
{
 // int fstNameLen = std::lengh.Field_value[0];
 // std::string         firstName;
 // if (()fstNameLen = (std::lenght.Field_value[0])) > 10);

  //  int j = 0;
//    while (j < 11)
//    {
//    check(Field_value[i])
        std::cout << "|         " << i + 1 << "|";
        std::cout << Field_value[0] << "|";
        std::cout << Field_value[1] << "|";
        std::cout << Field_value[2] << "|";

     //  .Field_value[j];// << std::endl;
//        j++;
//    }
    std::cout << std::endl;
//std::cout << int << 
}


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

    //std::cin.ignore();

//    i = 0;
//    std::cout << "oups" << std::endl;
//    while (i < 11)
//    {
//        std::cout << Contact::Field_name[i];
//        std::cout << Contact::Field_value[i];
//        std::cout << std::endl;//<< Contact::Field_value[i] 
//        i++;
//    }
//    std::getline(std::cin, firstName);
//    std::cin.ignore();
//    std::cout << "First Name : " << Contact::Field_name[0]  << std::endl;;
    return;
}
Contact::~Contact(void)
{
    std::cout << "j'appelle le destructeur contact" << std::endl;
    return; //facultatif
}