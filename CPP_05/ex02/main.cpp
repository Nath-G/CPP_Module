/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:42:28 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/26 12:14:58 by nagresel         ###   ########.fr       */
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
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <ctime>

void    test_instanciation_0(std:: string nameForm)
{
    std::cout << BLUE << "--- Test#0: Bureaucrat whithout parameters (so too low grade to sign form) and Shrubbery creation ---" << C_RES << std::endl;
    Bureaucrat  test;
    ShrubberyCreationForm  foo(nameForm);
    try
    {
        std::cout << GREEN_B << test << C_RES;
        std::cout << GREEN_B << foo << C_RES;
        foo.beSigned(test);
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_instanciation_1(std:: string nameForm)
{
    std::cout << BLUE << "--- Test#1: Bureaucrat whithout parameters (so too low grade to sign form) and Shrubbery creation, then promote then sign then same with copy instanciation ---" << C_RES << std::endl;
    Bureaucrat  sbdy;
    ShrubberyCreationForm  paper(nameForm);
    try
    {
        std::cout << GREY << "Step 1 - instanciation bureaucrat and form" << C_RES << std::endl;
        std::cout << GREEN_B << sbdy << C_RES;
        std::cout << GREEN_B << paper << C_RES;
        sbdy.signForm(paper); //cannot be signed because grade too low
        std::cout << GREY << "** promote **" << std::endl;
        for (int i = 0; i < 5; i++) //promote
            sbdy.incrementGrade();
        std::cout << GREEN_B << sbdy << C_RES;
        sbdy.signForm(paper);
        sbdy.executeForm(paper); // try to execute but grade too low
        std::cout << GREEN_B << paper << C_RES;
        std::cout << GREY << "Step 2 - instanciation by copy" << C_RES << std::endl;
        ShrubberyCreationForm  paper2(paper); //instanciate by copy
        std::cout << GREEN_B << paper2 << C_RES;
        std::cout << GREEN_B << sbdy << C_RES;
        sbdy.executeForm(paper2); //cannot be executed because it's unsigned
        sbdy.signForm(paper2);
        sbdy.executeForm(paper2); //cannot be executed because grade too low
        std::cout << GREY << "** promote **" << std::endl;
        for (int i = 0; i < 8; i++) //promote
            sbdy.incrementGrade();
        std::cout << GREEN_B << sbdy << C_RES;
        sbdy.executeForm(paper2);
        std::cout << GREEN_B << paper2 << C_RES;
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_instanciation_2(std:: string nameForm)
{
    std::cout << BLUE << "--- Test#2: Bureaucrat whithout parameters (so too low grade to sign form) and Presidential Pardon ---" << C_RES << std::endl;
    Bureaucrat  test;
    PresidentialPardonForm  foo(nameForm);
    try
    {
        std::cout << GREEN_B << test << C_RES;
        std::cout << GREEN_B << foo << C_RES;
        foo.beSigned(test);
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}

void    test_instanciation_3(std:: string nameForm)
{
    std::cout << BLUE << "--- Test#3: Bureaucrat whithout parameters (so too low grade to sign form) and Presidential Pardon, then promote then sign ---" << C_RES << std::endl;
    Bureaucrat  sbdy;
    PresidentialPardonForm  sheet(nameForm);
    try
    {
       std::cout << GREEN_B << sbdy << C_RES;
        std::cout << GREEN_B << sheet << C_RES;
        sbdy.signForm(sheet); //cannot be signed because grade too low
        std::cout << GREY << "** promote **" << std::endl;
        for (int i = 0; i < 125; i++) //promote
            sbdy.incrementGrade();
        std::cout << GREEN_B << sbdy << C_RES;
        sbdy.signForm(sheet);
        sbdy.executeForm(sheet); // try to execute but grade too low
        std::cout << GREEN_B << sheet << C_RES;
        std::cout << GREY << "** promote **" << std::endl;
        for (int i = 0; i < 20; i++) //promote
            sbdy.incrementGrade();
        std::cout << GREEN_B << sbdy << C_RES;
        sbdy.executeForm(sheet); // try to execute but grade too low
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}
void    test_instanciation_4(std:: string nameForm)
{
    std::cout << BLUE << "--- Test#4: Bureaucrat whithout parameters (so too low grade to sign form) and Robotomy Request ---" << C_RES << std::endl;
    Bureaucrat  test;
    RobotomyRequestForm  Rob(nameForm);
    try
    {
        std::cout << GREEN_B << test << C_RES;
        std::cout << GREEN_B << Rob << C_RES;
        Rob.beSigned(test);
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}


void    test_instanciation_5(std:: string nameForm)
{
    std::cout << BLUE << "--- Test#5: Bureaucrat whithout parameters (so too low grade to sign form) and Robotomy Request, then promote then sign ---" << C_RES << std::endl;
    Bureaucrat  sbdy;
    RobotomyRequestForm  rob(nameForm);
    try
    {
       std::cout << GREEN_B << sbdy << C_RES;//promote
        std::cout << GREEN_B << rob << C_RES;
        sbdy.signForm(rob); //cannot be signed because grade too low 
        std::cout << GREY << "** promote **" << std::endl;
        for (int i = 0; i < 78; i++) 
            sbdy.incrementGrade();
        std::cout << GREEN_B << sbdy << C_RES;
        sbdy.signForm(rob);
        sbdy.executeForm(rob); // try to execute but grade too low
        std::cout << GREY << "** promote **" << std::endl;
        for (int i = 0; i < 27; i++) //promote
            sbdy.incrementGrade();
        std::cout << GREEN_B << sbdy << C_RES;
        sbdy.executeForm(rob); // try to execute but grade too low
    }
    catch(std::exception &e)
    {
        std::cout << CORAIL << e.what() << C_RES << std::endl;
    }
}


int main()
{
    test_instanciation_0("home");
        std::cout << std::endl;

    test_instanciation_1("Guy's");
        std::cout << std::endl;
    test_instanciation_2("Somebody lower");
        std::cout << std::endl;
    test_instanciation_3("Somebody lower");
        std::cout << std::endl;
    std::srand(std::time(0));
    test_instanciation_4("Nobody");
        std::cout << std::endl;
    std::srand(std::time(0));
    test_instanciation_5("Nobody");
return (0);
}
