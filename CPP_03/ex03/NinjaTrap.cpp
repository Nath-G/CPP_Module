/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:59:46 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/21 16:17:10 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap():ClapTrap()
{
    this->_name = ClapTrap::_name;
    this->_type = "NINJ4-TP";
    this->ClapTrap::_hit_points = 60;
    this->ClapTrap::_max_hit_points = 60;
    this->ClapTrap::_nrj_points = 120;
    this->ClapTrap::_max_nrj_points = 120;
    this->ClapTrap::_armor_damage_reduction = 0;
    this->ClapTrap::melee_damage = 60;
    this->ClapTrap::ranged_damage = 5;
    std::cout  << _type << " " << _name 
    << ": \"I'm a robot ninja...\" (NinjaTrap constructor)"
    << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap()
{
    _name = name;
    this->_type = "NINJ4-TP";
    this->ClapTrap::_hit_points = 60;
    this->ClapTrap::_max_hit_points = 60;
    this->ClapTrap::_nrj_points = 120;
    this->ClapTrap::_max_nrj_points = 120;
    this->ClapTrap::_armor_damage_reduction = 0;
    this->ClapTrap::melee_damage = 60;
    this->ClapTrap::ranged_damage = 5;
    std::cout << _type << " " << _name 
    << ": \"Merciless Killing Machine: The inner workings of a monicidal apparatus.\" (NinjaTrap constructor)"
    << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &copy) : ClapTrap(copy)
{
    std::cout << _type << " Copy class from NinjaTrap(copy)"<< std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
    std::cout  << _type << " " << _name << ": \"I'm a robot ninja...\" (NinjaTrap destructor)" << std::endl;
}

void        NinjaTrap::ninjaShoebox(ClapTrap const &target)
{
    std::cout << "\"Take that!\" " << _type << " " << _name << " uses " << target.ClapTrap::_type << " " << target.ClapTrap::_name << "'s custom attack!" << std::endl;
}
        
void        NinjaTrap::ninjaShoebox(FragTrap const &target)
{
    std::cout << "\"Bop!\"       " << _type << " " << _name << " uses " << target.FragTrap::_type << " " << target.FragTrap::_name << "'s custom attack!" << std::endl;
}
void        NinjaTrap::ninjaShoebox(ScavTrap const &target)
{
    std::cout << "\"Hyah!\"      " << _type << " " << _name << " uses " << target.ScavTrap::_type << " " << target.ScavTrap::_name << "'s custom attack!" << std::endl;
}

void        NinjaTrap::ninjaShoebox(NinjaTrap const &target)
{
    std::cout << "\"Heyyah!\"    " << _type << " " << _name << " uses " << target.NinjaTrap::_type << " " << target.NinjaTrap::_name << "'s custom attack!" << std::endl;
}
