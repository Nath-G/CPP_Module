/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:15:49 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 13:40:52 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
    this-> _names[0] = "Freddy";
    this-> _names[1] = "Hannibal Lecter";
    this-> _names[2] = "Milton";
    this-> _names[3] = "Cole Sear";
    this-> _names[4] = "Jack Torrance";
    this-> _names[5] = "Christine";
    this-> _names[6] = "The Clown";
    this-> _names[7] = "Seth Brundle";
    this-> _names[8] = "BeetleJuice";
    this-> _names[9] = "Jason";
    this->_zombieNb = n;
    if (n <= 0)
        std::cout << "Error : zombie number has to be greater than 0 : the horde is set to 5 zombies !" << std::endl;
    this->_zombieNb = n <= 0 ? 5 : n;
    srand(time(NULL));
    this->_zombies = new Zombie[this->_zombieNb];
    for (int i = 0; i < _zombieNb; i++)
    {
            _zombies[i].setName(_names[rand() % 10]);
            _zombies[i].setType("default");
    }
}

ZombieHorde::~ZombieHorde()
{
    std::cout << std::endl;
    delete [] this->_zombies;
}


void    ZombieHorde::announce() const
{
    for (int i = 0; i < _zombieNb; i++)
    {
        _zombies[i].announce();
    }
}