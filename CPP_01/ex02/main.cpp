/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:31:26 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 14:17:34 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>
#include <string>

int     main()
{
    std::cout << "##### Create a Zombie on the Heap ########with the default type and a name ##" << std::endl;
    ZombieEvent ZombieTest = ZombieEvent();
    
    std::cout << "##with the default type and a name ##" << std::endl;
    Zombie* HeapZombie = ZombieTest.newZombie("Jane Doe");
    HeapZombie->announce();
    delete HeapZombie;

    std::cout << std::endl << "## with the type required and a name ##" << std::endl;
    ZombieTest.setZombieType("whatIwant");
    HeapZombie = ZombieTest.newZombie("John Doe");
    HeapZombie->announce();
    delete HeapZombie;

    std::cout << std::endl << "## Create a Zombie on the Stack with the type required and a name ##" << std::endl;
    ZombieTest.setZombieType("whatIwant2");
    ZombieTest.randomChump();

    return (0);
}