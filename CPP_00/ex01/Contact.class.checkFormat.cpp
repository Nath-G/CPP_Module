/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.checkFormat.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:57:27 by nagresel          #+#    #+#             */
/*   Updated: 2021/05/27 13:00:31 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

std::string    Contact::check_firstName(std::string input)
{
    int i = -1, j = 0;

    while (input[++i])
    {
        if (!(input[i] == '-') && (!(input[i] >= 'A') || !(input[i] <= 'Z'))
        && (!(input[i] >= 'a') || !(input[i] <= 'z')))
        {
            input.erase(i, 1);
            j++;
            i--;
        }
    }
    return (input);
}

std::string    Contact::check_lastAndNickNameAndFavoriteMealAndUnderwearColor(std::string input)
{
    int i = -1, j = 0;

    while (input[++i])
    {
        if (!(input[i] == '-') && !(input[i] == ' ' && i != 0)
        && (!(input[i] >= 'A') || !(input[i] <= 'Z'))
        && (!(input[i] >= 'a') || !(input[i] <= 'z')))
        {
            input.erase(i, 1);
            j++;
            i--;
        }
    }
    return (input);
}

std::string    Contact::check_login(std::string input)
{
    int i = -1, j = 0;

    while (input[++i])
    {
        if ((!(input[i] >= 'a') || !(input[i] <= 'z')))
        {
            input.erase(i, 1);
            j++;
            i--;
        }
    }
    return (input);
}

std::string    Contact::check_postalAddress(std::string input)
{
    int i = -1, j = 0;

    while (input[++i])
    {
        if (!(input[i] == '-') && !(input[i] == ' ' && i != 0)
        && (!(input[i] >= '0') || !(input[i] <= '9'))
        && (!(input[i] >= 'A') || !(input[i] <= 'Z'))
        && (!(input[i] >= 'a') || !(input[i] <= 'z')))
        {
            input.erase(i, 1);
            j++;
            i--;
       }
    }
    return (input);
}

std::string    Contact::check_emailAddress(std::string input)
{
    int i = -1;

    while (input[++i])
    {
        if (!(input[i] == '-') && !(input[i] == '.') && !(input[i] == '@')
        && !(input[i] == '_') && (!(input[i] >= '0') || !(input[i] <= '9'))
        && (!(input[i] >= 'a') || !(input[i] <= 'z')))
        {
            input = "";
            std::cout << "---  Format is not correct ! ---" << std::endl;
            break;
        }
    }
    return (input);
}

std::string    Contact::check_phone(std::string input)
{
    int i = -1, j = 0;

    while (input[++i])
    {
        if (!(input[i] == '.') && !(input[i] == '+') && !(input[i] == '(')
        && !(input[i] == ')') && (!(input[i] >= '0') || !(input[i] <= '9')))
        {
            input.erase(i, 1);
            j++;
            i--;
        }
    }
    return (input);
}

std::string    Contact::check_birthdayDate(std::string input)
{
    int i = -1;

    while (input[++i])
    {
        if (((input[i] < '0' || input[i] > '9') && ((i >=0 && i <= 3) || (i >= 5 && i <= 6) || (i >= 8 && i <= 9)))
        || (input[i] != '/' && (i == 4 || i == 7)) || (i > 9) || (input[0] != '2' && input[0] != '1')
        || (input[0] == '1' && input[1] != '9') || (input[5] != '0' && input[5] != '1')
        || (input[5] == '1' && (input[6] < '0' || input[6] > '2'))
        || (input[8] < '0' || input[8] > '3') || (input[8] == '3' && (input[9] < '0' || input[9] > '1'))
        || (input[8] == '3' && input[9] == '1' && ((input[5] == '0' && input[6] == '2') || input[6] == '4' || input[6] == '6' || input[6] == '9' || (input[5] == '1' && input[6] == '1')))
        || (input[5] == '0' && input[6] == '2' && input[8] == '3' && input[9] == '0')
        ||  (input[5] == '0' && input[6] == '0') || (input[8] == '0' && input[9] == '0'))
        {
            input = "";
            break ;
        }
    }
    if (input.length() != 10)
    {
        input = "";
        std::cout << "---  Format is not correct ! ---" << std::endl;
    }
    return (input);
}

std::string    Contact::check_darkSecret(std::string input)
{
    int i = -1, j = 0;

    while (input[++i])
    {
        if (!(input[i] == '-') && !(input[i] == ' ' && i != 0) && !(input[i] == '.') 
        && (!(input[i] == '(') && !(input[i] == ')')  && !(input[i] == '(') )
        && (!(input[i] >= 'A') || !(input[i] <= 'Z'))
        && (!(input[i] >= 'a') || !(input[i] <= 'z')))
        {
            input.erase(i, 1);
            j++;
            i--;
       }
    }
    return (input);
}

