/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:41:08 by nagresel          #+#    #+#             */
/*   Updated: 2021/05/12 12:12:55 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Contact.class.hpp"
#include "annuaire.hpp"

void    show_startup(void)
{
    std::cout << "Welcome to myContactBook" << std::endl;
    std::cout << "Available commands are :" << std::endl;
    std::cout << "  ADD to add a contact" << std::endl;
    std::cout << "  SEARCH to search a contact" << std::endl;
    std::cout << "  EXIT to exit from myContactBook" << std::endl;
    std::cout << "Please, chose a command: " << std::endl;
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
  //  int         run;
  //  std::string command;
  //  run = true;
    while (run)
    {
       std::getline(std::cin, cmd);
       if (cmd == "ADD")
       { 
            if (i < 8)
           {
                contact[i].add_contact();
               i++;
           }
           else
                std::cout << "Max contact number is triggered !" << std::endl;
       }
       else if (cmd == "EXIT")
            run = 0;
       else
           std::cout << "This command is not available, please use ADD, SEARCH or EXIT" << std::endl;
       /* code */
    }
    return (0);
}