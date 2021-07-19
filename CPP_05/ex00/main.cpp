/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:42:28 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/09 12:55:03 by nagresel         ###   ########.fr       */
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
# include <string>
# include <iostream>

void    test_instanciation_0()
{
    std::cout << BLUE << "--- Instanciation test whithout parameter ---" << C_RES << std::endl;
    try
    {
        Bureaucrat test;
        std::cout << GREEN_B << test << C_RES;
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_instanciation_1(std:: string name, int grade)
{
    std::cout << BLUE << "--- Instanciation test whith fair parameters ---" << C_RES << std::endl;
    try
    {
        Bureaucrat test(name, grade);
        std::cout << GREEN_B << test << C_RES;
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;

    }
}

void    test_instanciation_2(std:: string name, int grade)
{
    std::cout << BLUE << "--- Instanciation test whith grade too low ---" << C_RES << std::endl;
    try
    {
        Bureaucrat test(name, grade);
        std::cout << GREEN_B << test << C_RES;
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}


void    test_instanciation_3(std:: string name, int grade)
{
    std::cout << BLUE << "--- Instanciation test whith grade too high ---" << C_RES << std::endl;
    try
    {
        Bureaucrat test(name, grade);
        std::cout << GREEN_B << test << C_RES;
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_instanciation_4(std::string name, int grade)
{
    std::cout << BLUE << "--- Instanciation test by copy then increment and decrement---" << C_RES << std::endl;
    try
    {
        Bureaucrat test0(name, grade);
        Bureaucrat test1(test0);

        std::cout << GREEN_B << test0 << C_RES;
        std::cout << GREEN_B << test1 << C_RES;
        test1.incrementGrade();
        std::cout << YELLOW << test1 << C_RES;
        test1.decrementGrade();
        std::cout << YELLOW << test1 << C_RES;

    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_promote_0()
{
    std::cout << BLUE << "--- Instanciation test whithout parameters promote from 150 to 0 ---" << C_RES << std::endl;
    Bureaucrat test;
    
    while (test.getGrade() > - 1)
    {
        try
        {
            test.incrementGrade();
            std::cout << GREEN_B << test << C_RES;
        }
        catch(std::exception &e)
        {
            std::cout << CORAIL << e.what() << C_RES << std::endl;
            break;
        }
    }
    
}

void    test_promote_1(std:: string name, int grade)
{
    std::cout << BLUE << "--- Instanciation test whith parameters promote from 150 to 0 ---" << C_RES << std::endl;
    Bureaucrat test(name, grade);
    
    while (test.getGrade() > - 1)
    {
        try
        {
            test.incrementGrade();
            std::cout << GREEN_B << test << C_RES;
        }
        catch(std::exception &e)
        {
            std::cout << CORAIL << e.what() << C_RES << std::endl;
            break;
        }
    }
    
}

void    test_demote_0()
{
    std::cout << BLUE << "--- Instanciation test whithout parameters demote from 150 to 151 ---" << C_RES << std::endl;
    Bureaucrat test;
    
    while (test.getGrade() < 151)
    {
        try
        {
            test.decrementGrade();
            std::cout << GREEN_B << test << C_RES;
        }
        catch(std::exception &e)
        {
            std::cout << CORAIL << e.what() << C_RES << std::endl;
            break;
        }
    }
}

void    test_demote_1(std:: string name, int grade)
{
    std::cout << BLUE << "--- Instanciation test whith parameters demote from 1 to 150 ---" << C_RES << std::endl;
    Bureaucrat test(name, grade);
    
    while (test.getGrade() < 151)
    {
        try
        {
            test.decrementGrade();
            std::cout << GREEN_B << test << C_RES;
        }
        catch(std::exception &e)
        {
            std::cout << CORAIL << e.what() << C_RES << std::endl;
            break;
        }
    }
}

int main()
{
    test_instanciation_0();
    std::cout << std::endl;
    test_instanciation_1("Me", 1);
    std::cout << std::endl;
    test_instanciation_2("Beth", 210);
    std::cout << std::endl;
    test_instanciation_3("Shirley", 0);
    std::cout << std::endl;
    test_instanciation_4("Copy", 50);
    test_promote_0();
    std::cout << std::endl;
    test_promote_1("Lucky", 150);
    std::cout << std::endl;
    test_demote_0();
    std::cout << std::endl;
    test_demote_1("Unlucky", 1);
return (0);
}
