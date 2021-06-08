/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:20:53 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 16:09:05 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*Weapon::Weapon() : _type("default")
{
}*/

Weapon::Weapon(std::string type) : _refType(this->_type), _type(type)
{
}

Weapon::~Weapon()
{   
}

const std::string     &Weapon::getType() const
{
    return(this->_refType);
}

void            Weapon::setType(std::string newType)
{
    _type = newType;
}

