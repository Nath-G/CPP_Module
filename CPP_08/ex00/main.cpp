/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:05:30 by nagresel          #+#    #+#             */
/*   Updated: 2021/09/17 13:33:30 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

# define GREY	"[90m"
# define C_RES	"[0m"

template <typename T>
void test(T &container, int n)
{
    try
    {
        int result = easyfind(container, n);
        std::cout << "Number: " << result << " is in the container" << std::endl;
    }
    catch (std::exception &e) {std::cout << "Number: " << n << " raises a " << e.what() << std::endl;}
    std::cin.get();
}

int main()
{
	std::vector<int> vector;
	std::list<int> list;

	std::cout << GREY << "--- Using easyfind on empty containers ---" << C_RES << std::endl << std::endl;
    test(list, 120);
    test(vector, 1);
   
   	std::cout << GREY << "--- Filling containers with even values from 0 to 198";
    for (int index = 0; index < 100; ++index)
		vector.push_back(index * 2);
    for (int index = 0; index < 100; ++index)
		list.push_back(index * 2);
    std::cout << GREY << " then test again ---" << C_RES << std::endl << std::endl;
    test(vector, 0);
    test(vector, 2);
    test(vector, 198);
    test(vector, -1);
    test(vector, 1);
    test(vector, 151);
    test(vector, 200);

    test(list, 0);
    test(vector, 4);
    test(list, 198);
    test(list, -2);
    test(list, 3);
    test(list, 151);
    test(list, 202);

    return (0);
}