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

Contact::Contact(void)
{
    return;
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
                "Upper/lowercase and - are autorised, others will be removed ***************** ",
                "Upper/lowercase, - and space are autorised, others will be removed ********** ",
                "Upper/lowercase, - and space are autorised, others will be removed ********** ",
                "lowercase are autorised, others will be removed ***************************** ",
                "Upper/lowercase, numbers, - and space are autorised, others will be removed * ",
                "Lowercase,numbers -_.@ are autorised **************************************** ",
                "Numbers and .()+ are autorised, others will be removed ********************** ",
                "Format YYYY/MM/DD *********************************************************** ",
                "Upper/lowercase, - and space are autorised, others will be removed ********** ",
                "Upper/lowercase, - and space are autorised, others will be removed ********** ",
                "Upper/lowercase, .,-() and space are autorised, others will be removed ****** ",
        };


std::string    Contact::check_information(std::string input, int fieldName)
{
    if (input == "")
        return(input);
    else if (fieldName == FirstName)
        input = check_firstName(input);
    else if (fieldName == LastName || fieldName == NickName || fieldName == FavoriteMeal || fieldName == UnderwearColor)
        input = check_lastAndNickNameAndFavoriteMealAndUnderwearColor(input);
    else if (fieldName == Login)
        input = check_login(input);
    else if (fieldName == PostalAddress)
        input = check_postalAddress(input);
    else if (fieldName == EmailAddress)
        input = check_emailAddress(input);
    else if (fieldName == Phone)
        input = check_phone(input);
    else if (fieldName == BirthdayDate)
        input = check_birthdayDate(input);
    else if (fieldName == DarkestSecret)
        input = check_darkSecret(input);
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
    return (0);
}

Contact::~Contact(void)
{
    return;
}