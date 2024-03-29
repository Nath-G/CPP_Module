/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:31:38 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 14:12:57 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
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
    this->_type	= 		"default";
}

ZombieEvent::~ZombieEvent(void)
{
}

Zombie* ZombieEvent::newZombie (std::string name)
{
    return(new Zombie(this->_type, name));
}

void    ZombieEvent::setZombieType(std::string type)
{
    this->_type = type;
}

void    ZombieEvent::randomChump(void)
{
    std::string randomName;

    srand (time(NULL));
    randomName = this->_names[rand() % 10];
    Zombie zombie = Zombie(this->_type, randomName);
    zombie.announce();
}
