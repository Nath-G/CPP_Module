/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:42:28 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/23 18:07:45 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Colors
# define GREY		"[90m"
# define C_RES		"[0m"
# define YELLOW		"[33m"
# define BLUE		"[34m"
# define COLOR(id)	"[38;5;"#id"m"
# define CORAIL		COLOR(168)
# define ORANGE		COLOR(130)
# define SKY_BLUE	COLOR(69)
# define GREEN_B	"[32;01m"
# define RED 		"[31m"

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>

void    test_instanciation_0(std:: string nameForm, std:: string target)
{
    std::cout << BLUE << "--- Test#0: Bureaucrat whithout parameters (so too low grade to sign form) and " << nameForm << " creation ---" << C_RES << std::endl;
    Bureaucrat  test;
    Intern      bob;
    try
    {
        Form *foo = bob.makeForm(nameForm, target);
        std::cout << GREEN_B << test << C_RES;
        std::cout << GREEN_B << *foo << C_RES;
        test.signForm(*foo);
        delete foo;
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_instanciation_1(std:: string nameForm, std:: string target, int signGrade, int execGrade)
{
    std::cout << BLUE << "--- Test#1: Bureaucrat penPusher (can sign but not execute) and Bureaucrat chief and " << nameForm << " creation, penPusher signs then try to execute without success, then chief executs ---" << C_RES << std::endl;
    Bureaucrat  nbdy("penPusher", signGrade);
    Bureaucrat  sbdy("Chief", execGrade);
    Intern      bob;

    try
    {
        Form *paper = bob.makeForm(nameForm, target);
        std::cout << GREEN_B << nbdy << C_RES;
        std::cout << GREEN_B << sbdy << C_RES;
        std::cout << GREEN_B << *paper << C_RES;
        nbdy.signForm(*paper);
        nbdy.executeForm(*paper); // try to execute but grade too low
        sbdy.executeForm(*paper);
        std::cout << GREEN_B << *paper << C_RES;
        delete paper;
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

int main()
{
   test_instanciation_0("shrubbery creation", "home");
        std::cout << std::endl;
    test_instanciation_0("robotomy request", "rob");
        std::cout << std::endl;
   test_instanciation_0("presidential pardon", "tom");
        std::cout << std::endl;
    test_instanciation_0("oups", "home");
        std::cout << std::endl;
    test_instanciation_1("shrubbery creation", "home", 145, 137);
        std::cout << std::endl;
            std::srand(std::time(0));
    test_instanciation_1("robotomy request", "rob", 72, 45);
        std::cout << std::endl;
    test_instanciation_1("presidential pardon", "tom", 25, 5);
        std::cout << std::endl;
return (0);
}
