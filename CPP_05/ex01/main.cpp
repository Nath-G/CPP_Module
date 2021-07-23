/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:42:28 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/23 19:17:10 by nagresel         ###   ########.fr       */
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
    std::cout << BLUE << "--- Test#0: Bureaucrat whithout parameters (so too low grade to sign form) ---" << C_RES << std::endl;
    Bureaucrat  test;
    Form        form;
    
    try
    {
        std::cout << GREEN_B << test << C_RES;
        std::cout << GREEN_B << form << C_RES;
        test.signForm(form);
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_instanciation_1(std:: string name, int grade)
{
    std::cout << BLUE << "--- Test#1: Bureaucrat whith fair grade to sign (no form parameters) ---" << C_RES << std::endl;
    try
    {
        Bureaucrat  test(name, grade);
        Form        form;
        std::cout << GREEN_B << test << C_RES;
        std::cout << GREEN_B << form << C_RES;
        test.signForm(form);
        std::cout << GREEN_B << form << C_RES;

    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_instanciation_2(std:: string name, int grade)
{
    std::cout << BLUE << "--- Test#2: Bureaucrat whith grade too low to sign (no form parameters) ---" << C_RES << std::endl;
    try
    {
        Bureaucrat test(name, grade);
        Form        form;

        std::cout << GREEN_B << test << C_RES;
        std::cout << GREEN_B << form << C_RES;
        test.signForm(form);
        std::cout << GREEN_B << form << C_RES;

    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}


void    test_instanciation_3(std:: string name, int grade, std:: string nameForm, int signGradRequired, int execGradeRequired)
{
    std::cout << BLUE << "--- Test#3: Bureaucrat and form parameters and fair grade to sign ---" << C_RES << std::endl;
    try
    {
        Bureaucrat test(name, grade);
        Form        form(nameForm, signGradRequired, execGradeRequired);
        std::cout << GREEN_B << test << C_RES;
        std::cout << GREEN_B << form << C_RES;
        test.signForm(form);
        std::cout << GREEN_B << form << C_RES;
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_instanciation_4(std:: string name, int grade, std:: string nameForm, int signGradRequired, int execGradeRequired)
{
    std::cout << BLUE << "--- Test#4: Bureaucrat and form parameters and grade too low to sign ---" << C_RES << std::endl;
    try
    {
        Bureaucrat test(name, grade);
        Form       form(nameForm, signGradRequired, execGradeRequired);
        std::cout << GREEN_B << test << C_RES;
        std::cout << GREEN_B << form << C_RES;
        test.signForm(form);
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_instanciation_5(std::string name, int grade, std:: string nameForm, int signGradRequired, int execGradeRequired)
{
    std::cout << BLUE << "--- Test#5: Instanciation test by copy fair grad, copy sign then src sign a form already signed then increment and decrement---" << C_RES << std::endl;
    try
    {
        Bureaucrat test0(name, grade);
        Bureaucrat test1(test0);
        Form       form(nameForm, signGradRequired, execGradeRequired);

        std::cout << GREEN_B << test1 << C_RES;
        std::cout << GREEN_B << form << C_RES;
        test1.signForm(form);
        std::cout << GREEN_B << form << C_RES;
        test0.signForm(form);
        std::cout << GREEN_B << test0 << C_RES;
        std::cout << YELLOW << test1 << C_RES;
        test1.incrementGrade();
        test0.incrementGrade();
        std::cout << GREEN_B << test0 << C_RES;
        std::cout << YELLOW << test1 << C_RES;
        test1.decrementGrade();
        test0.decrementGrade();
        std::cout << GREEN_B << test0 << C_RES;
        std::cout << YELLOW << test1 << C_RES;
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_promote_0()
{
    std::cout << BLUE << "--- Test#6:Instanciation test whithout parameters promote from 150 to 0 ---" << C_RES << std::endl;
    Bureaucrat  test;
    Form        form;
    std::cout << GREEN_B << test << C_RES;
    std::cout << GREEN_B << form << C_RES;
    test.signForm(form);
    std::cout << GREY << "### promote test untill 20 ###" << C_RES << std::endl;
    while (test.getGrade() > 20)
    {
        try
        {
            test.incrementGrade();
        }
        catch(std::exception &e)
        {
            std::cout << CORAIL << e.what() << C_RES << std::endl;
            break;
        }
    }
    std::cout << GREEN_B << test << C_RES;
    test.signForm(form);
    std::cout << GREEN_B << form << C_RES;
}

void    test_promote_1(std:: string name, int grade)
{
    std::cout << BLUE << "--- Test#7: Instanciation test whith parameters promote from 150 to 0 ---" << C_RES << std::endl;
    
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
    std::cout << BLUE << "--- Test#8: Instanciation test whithout parameters demote from 150 to 151 ---" << C_RES << std::endl;
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
    std::cout << BLUE << "--- Test#9: Instanciation test whith parameters demote from 1 to 150 ---" << C_RES << std::endl;
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
    test_instanciation_2("Beth", 30);
    std::cout << std::endl;
    test_instanciation_3("Shirley", 10, "Annoying", 15, 50);
    std::cout << std::endl;
    test_instanciation_4("Shirley", 10, "Annoying", 5, 50);
    std::cout << std::endl;
    test_instanciation_5("Copy", 20, "Annoying", 25, 50);
    std::cout << std::endl;
    test_promote_0();
/*  std::cout << std::endl;
    test_promote_1("Lucky", 150);
    std::cout << std::endl;
    test_demote_0();
    std::cout << std::endl;
    test_demote_1("Unlucky", 1);
*/
return (0);
}
