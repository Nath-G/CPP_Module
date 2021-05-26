/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:41:08 by nagresel          #+#    #+#             */
/*   Updated: 2021/05/26 19:01:20 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "annuaire.hpp"

void    show_startup(void)
{
    std::cout << "----- Welcome to myContactBook -----" << std::endl;
    std::cout << "Available commands are : ADD, SEARCH, EXIT" << std::endl;
}

int main(void) 
{
    Contact     contact[8];
    std::string cmd;
    int         run;
    int         i;

    run = true;
    i = 0;
    show_startup();
    while (run)
    {
        std::cout << "Please, choose a command: ";
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
        { 
            if (i < 8)
            {
                if(!contact[i].add_contact())
                    i++;
           }
           else
                std::cout << "Max contact number is triggered !" << std::endl;
        }
        else if (cmd == "SEARCH")
        {
            if(contact[0].exists())
            {
                show_contact_list(contact);
                contact[choose_contact(contact)].show_contact();
            }
            else
                std::cout << "MyContactBook is empty !" << std::endl;
       }
        else if (cmd == "EXIT")
            run = 0;
        else
           std::cout << "This command is not available, please use ADD, SEARCH or EXIT" << std::endl;
    }
    return (0);
}