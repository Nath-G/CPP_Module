/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:02:29 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/04 16:45:26 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void    ponyOnTheHeap()
{
    Pony *pony_Heap;

    pony_Heap = new Pony("Heap Pony", "Shetland", "Alezan", "0.98", "Apple");
    pony_Heap->show_up();
    pony_Heap->run();
    pony_Heap->cry();
    pony_Heap->eat();
    delete pony_Heap;
}

void    ponyOnTheStack()
{
    Pony pony_Stack("Stack Pony", "Camargue", "Mouse", "1.2", "Carot");
    pony_Stack.show_up();
    pony_Stack.run();
    pony_Stack.cry();
    pony_Stack.eat();
}

int     main()
{

    std::cout << "## Pony on the stack ##" << std::endl;
    ponyOnTheStack();
    std::cout << std::endl;
    std::cout << "## Pony on the heap ##" << std::endl;
    ponyOnTheHeap();
    std::cout << std::endl;
    std::cout << "## END ##" << std::endl;
    return (0);
}