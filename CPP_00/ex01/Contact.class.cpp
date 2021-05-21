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
                "Login:",
                "Postal address: ",
                "email address: ",
                "Phone number: ",
                "Birthday date: ",
                "Favorite meal: ",
                "Underwear color: ",
                "Darkest secret: "
        };

std::string  Contact::Field_info[11]  = {
                "Upper/lowercase and - are autorised, others will be remove ***************** ",
                "Upper/lowercase, - and space are autorised, others will be remove ********** ",
                "Upper/lowercase, - and space are autorised, others will be remove ********** ",
                "lowercase are autorised, others will be remove. **************************** ",
                "Upper/lowercase, numbers, - and space are autorised, others will be remove * ",
                "Lowercase,numbers -_.@ are autorised, others will be remove **************** ",
                "Numbers and .()+ are autorised, others will be remove *********************** ",
                "Format YYYY/MM/DD ********************************************************** ",
                "Upper/lowercase, - and space are autorised, others will be remove ********** ",
                "Upper/lowercase, - and space are autorised, others will be remove ********** ",
                "Upper/lowercase, .,-() and space are autorised, others will be remove ****** ",
        };

std::string    Contact::check_information(std::string input, int fieldName)
{
    int i = -1, j = 0;
    
    if (input == "")
        return(input);
    if (fieldName == FirstName)
    {
        while (input[++i])
        {
            if (!(input[i] == '-') && (!(input[i] >= 'A') || !(input[i] <= 'Z')) && (!(input[i] >= 'a') || !(input[i] <= 'z')))
            {
                input.erase(i, 1);
                j++;
                i--;
            }
        }
    }
    if (fieldName == LastName || fieldName == NickName)
    {
        while (input[++i])
        {
            if (!(input[i] == '-') && !(input[i] == ' ' && i != 0) && (!(input[i] >= 'A') || !(input[i] <= 'Z')) && (!(input[i] >= 'a') || !(input[i] <= 'z')))
            {
                input.erase(i, 1);
                j++;
                i--;
            }
        }
    }
    if (fieldName == Login)
    {
        while (input[++i])
        {
            if ((!(input[i] >= 'a') || !(input[i] <= 'z')))
            {
                input.erase(i, 1);
                j++;
                i--;
            }
        }
    }
    if (fieldName == PostalAddress)
    {
        while (input[++i])
        {
            if (!(input[i] == '-') && !(input[i] == ' ' && i != 0) && (!(input[i] >= '0') || !(input[i] <= '9')) && (!(input[i] >= 'A') || !(input[i] <= 'Z')) && (!(input[i] >= 'a') || !(input[i] <= 'z')))
            {
                input.erase(i, 1);
                j++;
                i--;
            }
        }
    }
    if (fieldName == EmailAddress)
    {
        while (input[++i])
        {
            if (!(input[i] == '-') && !(input[i] == '.') && !(input[i] == '@') && !(input[i] == '_') && (!(input[i] >= '0') || !(input[i] <= '9')) && (!(input[i] >= 'a') || !(input[i] <= 'z')))
            {
                input.erase(i, 1);
                j++;
                i--;
            }
        }
    }
    if (fieldName == Phone)
    {
        while (input[++i])
        {
            if (!(input[i] == '.') && !(input[i] == '+') && !(input[i] == '(') && !(input[i] == ')') && (!(input[i] >= '0') || !(input[i] <= '9')))
            {
                input.erase(i, 1);
                j++;
                i--;
            }
        }
    }
    if (fieldName == BirthdayDate)
    {
        while (input[++i])
        {
            if (!(input[i] == '/' && (i != 0 || i != 1 || i != 2 || i != 3 || i != 6 || i != 9)) && ((!(input[i] >= '0') || !(input[i] <= '9')) && (i != 4 || i != 7)))
            {
                input.erase(i, 1);
                j++;
                i--;
            }
        }
    }
    return(input);
}


void    Contact::set_information(std::string input, int fieldName)
{

    this->Field_value[fieldName] = input;
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
        do {
        std::cout << Contact::Field_info[value];
        std::cout << Contact::Field_name[value];
        std::getline(std::cin, input);
        input = Contact::check_information(input, value);
        Contact::set_information(input, value);
         } while (Field_value[value] == "");
    }
   
       // return (1);
    return (0);
}

Contact::~Contact(void)
{
    std::cout << "j'appelle le destructeur contact" << std::endl;
    return; //facultatif
}