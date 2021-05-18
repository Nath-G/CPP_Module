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

bool        Contact::exists(void)const
{
    return (this->Field_value[0] != "");
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

void    Contact::set_information(std::string input, int value)
{
    this->Field_value[value] = input;
}

void    Contact::show_contact(void)const
{
     int fieldName = 0;

    for(fieldName = FirstName; fieldName <= DarkestSecret; fieldName++)
    {

        std::cout << Field_name[fieldName] << Field_value[fieldName];
        std::cout << std::endl;
    }
    return;
}

void    Contact::show_contact_sumup(int i)const
{
    int strlen = 0, fieldName = 0;
    std::string  str ="";
    std::cout << "|         " << i + 1 << "|";
    for(fieldName = FirstName; fieldName < Login; fieldName++)
    {
       strlen = Field_value[fieldName].length();
        if (strlen < 11)
        {
            std::cout << std::setw(10) << std::right  << this->Field_value[fieldName];
            std::cout << "|";
        }
        else
        {
            str ="";
            str = this->Field_value[fieldName];
            str.resize (9);
            std::cout << str;std::cout << ".|";
        }
    }
    std::cout << std::endl;
}

int    Contact::add_contact(void)
{
    int value;
    std::string input;
    for(value = FirstName; value <= DarkestSecret; value++)
    {
        std::cout << Contact::Field_name[value];
        std::getline(std::cin, input);
        Contact::set_information(input, value);
    }
    if (Field_value[FirstName] == "")
        return (1);
    return (0);
}

Contact::~Contact(void)
{
    std::cout << "j'appelle le destructeur contact" << std::endl;
    return; //facultatif
}