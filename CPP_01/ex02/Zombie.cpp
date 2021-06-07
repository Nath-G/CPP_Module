/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:31:33 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/07 11:30:21 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    //Contructor
//    this->_name = "Jane Doe";
//    this->_type = "cueilleur";
}


Zombie::Zombie(std::string type, std::string name) : _type(type),  _name(name)
{
}

Zombie::~Zombie()
{
    std::cout << this->_name << " died." << std::endl;
    //destructor
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

void    Zombie::setType(std::string type)
{
    this->_type = type;
}

void    Zombie::announce() const
{
    std::cout << this->_name << " (" << this->_type << ") Braiiiiiiinnnssss ..." << std::endl;
}

