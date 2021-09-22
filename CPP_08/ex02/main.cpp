/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:28:42 by nagresel          #+#    #+#             */
/*   Updated: 2021/09/22 17:18:41 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>
#include <list>

# define GREY	"[90m"
# define C_RES	"[0m"

void    test_subject_mutantStack()
{
    std::cout << GREY << "***Test (from subject) with MutantStack container ***" << C_RES << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
//[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;
}
void    test_subject_list()
{
    std::cout << GREY << "*** Test (from subject) with std::list container ***" << C_RES << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
//[...]
    lst.push_back(0);
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> s(lst);
    std::cout << std::endl;
}

void    test_empty()
{
    std::cout << GREY << "*** Compare the return of empty function with full list and full MutantStack containers then with empty list and MutantStack containers ***" << C_RES << std::endl;
    MutantStack<int> ms;
    std::list<int> lst;
    MutantStack<int> ms_empty;
    std::list<int> lst_empty;
    ms.push(200);
    ms.push(300);
    lst.push_back(200);
    lst.push_back(300);

    std::cout << "the return of ms.empty() is      :  " << ms.empty() << std::endl;
    std::cout << "the return of lst.empty() is     :  " << lst.empty() << std::endl;
    std::cout << "the return of ms_empty.empty() is:  " << ms_empty.empty() << std::endl;
    std::cout << "the return of lst_empty.empty() is: " << lst_empty.empty() << std::endl;
    std::cout << std::endl;

}

void test_copy()
{
	std::cout << GREY << "*** TEST copy ***" << C_RES << std::endl;
	MutantStack<int> origin;
	origin.push(66);
	origin.push(666);

	MutantStack<int> copy(origin);
	std::cout << "copy has to contain 666  : " << static_cast<int>(copy.top()) << std::endl;
	copy.pop();
	std::cout << "origin size has to be 2: " << origin.size() << std::endl;
	std::cout << "copy size has to be 1  : " << copy.size() << std::endl;
	copy.pop();
	std::cout << "origin size has to be 2: " << origin.size() << std::endl;
	std::cout << "copy size has to be 0  : " << copy.size() << std::endl;
    
    std::cout << std::endl;
    
}

int main()
{
    test_subject_mutantStack();
    std::cin.get();
    test_subject_list();
    std::cin.get();
    test_empty();
    std::cin.get();
    test_copy();
    return 0;
}
