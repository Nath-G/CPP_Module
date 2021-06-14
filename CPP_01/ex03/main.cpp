/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:31:26 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/14 15:26:50 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int     main()
{

	srand(time(0));

	std::cout  << std::endl << "--- TEST#1: Horde of 4 zombies ---" << std::endl;
	ZombieHorde testHorde1(4);
	testHorde1.announce();

	std::cout  << std::endl << "--- TEST#2: Horde of 0 zombie ---" << std::endl;
	ZombieHorde testHorde2(0);
	testHorde2.announce();

	std::cout  << std::endl << "--- TEST#3: Horde of -5 zombies ---" << std::endl;
	ZombieHorde testHorde3(-5);
	testHorde3.announce();

	std::cout  << std::endl << "--- TEST#4: Horde of 20 zombies ---" << std::endl;
	ZombieHorde testHorde4(20);
	testHorde4.announce();

    return (0);
}