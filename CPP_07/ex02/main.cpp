/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:18:39 by nagresel          #+#    #+#             */
/*   Updated: 2021/08/09 13:25:20 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define GREY	"[90m"
# define C_RES	"[0m"
# define MAX_VAL 1000

#include <iostream>
#include <string>
#include <cstdlib>
#include "Array.hpp"

void	test_empty()
{
	std::cout << GREY << "*** TEST EMPTY ***" << C_RES << std::endl;
	Array<int> arr(0);
	std::cout << arr.size() << std::endl;
    Array<char> car(0);
	std::cout << car.size() << std::endl;
    std::cout << std::endl;

}

void 	test_basic_usage()
{
	std::cout << GREY << "*** TEST BASIC USAGE ***" << C_RES << std::endl;
    unsigned int size = 3;
	Array<int> arr(size);
    srand(time(NULL));
    std::cout << "Original initialisation: " << std::endl;
     for (unsigned int i = 0; i < size; i++)
    {
        std::cout << arr[i];
         if (i < (size - 1))
            std::cout << ", ";
    }
	std::cout << std::endl;
    std::cout << "Random initialisation: " << std::endl;
    for (unsigned int i = 0; i < size; i++)
    {
        const int value = rand() % MAX_VAL;
        arr[i] = value;
    }
    for (unsigned int i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i < (size - 1))
            std::cout << ", ";
    }
	std::cout << std::endl;
    std::cout << std::endl;

}

void 	test_out_of_range()
{
	std::cout << GREY << "*** TEST OUT OF RANGE INDEX ***" << C_RES << std::endl;
	Array<int> arr(4);

	try
	{
		std::cout << arr[9] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << std::endl;

}

void	test_copy()
{
	std::cout << GREY << "*** TEST COPY ***" << C_RES << std::endl;
	Array<std::string> original(2);
	std::cout << "Original initialisation: original[0] = '" << original[0] << "', original[1] = '" << original[1] << "'" << std::endl;
    original[0] = std::string("coucou");
	original[1] = std::string("lol");
	Array<std::string> copy(original);
	std::cout << "update original : " << original[0] << ", " << original[1] << std::endl;
	std::cout << "copy : " << copy[0] << ", " << copy[1] << std::endl << std::endl;
	std::cout << "update original : " << std::endl;
	original[0] = std::string("oups");
	std::cout << "original[0] = " << original[0] << std::endl;
	std::cout << "copy[0] = " << copy[0] << std::endl << std::endl;
	std::cout << "update copy : " << std::endl;
	copy[1] = std::string("toto");
	std::cout <<  "original[1] = " << original[1] << std::endl;
	std::cout << "copy[1] = " << copy[1] << std::endl;
    std::cout << std::endl;
}

void	test_assignement()
{
	std::cout << GREY << "*** TEST ASSIGNEMENT ***" << C_RES << std::endl;
	Array<std::string> original(2);
    std::cout << "Original initialisation: original[0] = '" << original[0] << "', original[1] = '" << original[1] << "'" << std::endl;
	original[0] = std::string("coucou");
	original[1] = std::string("lol");
	Array<std::string> assignement = original;

	std::cout << "original : " << original[0] << ", " << original[1] << std::endl;
	std::cout << "assignement : " << assignement[0] << ", " << assignement[1] << std::endl << std::endl;
	std::cout << "update original : " << std::endl;
	original[0] = std::string("oups");
	std::cout << "original[0] = " << original[0] << std::endl;
	std::cout << "assignement[0] = " << assignement[0] << std::endl << std::endl;
	std::cout << "update assignement : " << std::endl;
	assignement[1] = std::string("toto");
	std::cout <<  "original[1] = " << original[1] << std::endl;
	std::cout << "assignement[1] = " << assignement[1] << std::endl;

}
int main()
{
	test_basic_usage();
	test_empty();
	test_out_of_range();
	test_copy();
	test_assignement();
}