/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:28:48 by nagresel          #+#    #+#             */
/*   Updated: 2021/08/02 12:37:32 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define GREY		"[90m"
# define C_RES		"[0m"

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <string>
# include <iostream>

void identify_from_reference(Base & p)
{
    char type = 0;
    try
    {
        A a = dynamic_cast<A&>(p);
        type = 'A';
    }
    catch (std::exception &e){}
    try
    {
        B b = dynamic_cast<B&>(p);
        type = 'B';
    }
    catch (std::exception &e){}
    try
    {
        C c = dynamic_cast<C&>(p);
        type = 'C';
    }
    catch (std::exception &e){}
    if (type)
        std::cout << "Reference is identified as class: " << type << std::endl;
    else
        std::cout << "Reference is not identified!" << std::endl;
}

void identify_from_pointer(Base * p)
{
    char type = 0;
    if (A *a = dynamic_cast<A*>(p))
        type = 'A';
    else if (B *a = dynamic_cast<B*>(p))
        type = 'B';
    else if (C *a = dynamic_cast<C*>(p))
        type = 'C';
    if (type)
        std::cout << "Pointer is identified as class: " << type << std::endl;
    else
        std::cout << "Pointer is not identified!" << std::endl;
}

Base    *generate(void)
{
    int test = (rand() % 3);
    Base *ptr;
    char type;

    switch(test)
    {
        case 0:
            type = 'A';
            ptr = new A;
            break;
        case 1:
            type = 'B';
            ptr = new B;
            break;
        case 2:
            type = 'C';
            ptr = new C;
            break;
        default:
            std::cout << "Error" << std::endl;
            return (NULL);
    }
    std::cout << "Class " << type << " is generate." << std::endl;
    return (ptr);
}

int main ()
{
    srand(time(0));
    std::cout << GREY << "--- Genarate random class ---" << C_RES << std::endl;
    Base *basis = generate();
    identify_from_pointer(basis);
    identify_from_reference(*basis);

    std::cout << GREY << "--- Create basis without class generating ---" << C_RES << std::endl;
    Base *basis2 = new Base();
    identify_from_pointer(basis2);
    identify_from_reference(*basis2);

    delete basis;
    delete basis2;
}