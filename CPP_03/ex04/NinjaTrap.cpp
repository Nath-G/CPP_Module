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
    this->name = ClapTrap::name;
    this->type = "NINJ4-TP";
    this->ClapTrap::_hit_points = 60;
    this->ClapTrap::_max_hit_points = 60;
    this->ClapTrap::_nrj_points = 120;
    this->ClapTrap::_max_nrj_points = 120;
    this->ClapTrap::_armor_damage_reduction = 0;
    this->ClapTrap::melee_damage = 60;
    this->ClapTrap::ranged_damage = 5;
    std::cout  << type << " " << name 
    << ": \"I'm a robot ninja...\" (NinjaTrap constructor)"
    << std::endl;
}

NinjaTrap::NinjaTrap(std::string Name) : ClapTrap(Name)
{
    name = Name;
    this->type = "NINJ4-TP";
    this->ClapTrap::_hit_points = 60;
    this->ClapTrap::_max_hit_points = 60;
    this->ClapTrap::_nrj_points = 120;
    this->ClapTrap::_max_nrj_points = 120;
    this->ClapTrap::_armor_damage_reduction = 0;
    this->ClapTrap::melee_damage = 60;
    this->ClapTrap::ranged_damage = 5;
    std::cout << type << " " << name 
    << ": \"Merciless Killing Machine: The inner workings of a monicidal apparatus.\" (NinjaTrap constructor)"
    << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &copy) : ClapTrap(copy)
{
    std::cout << type << " Copy class from NinjaTrap(copy)"<< std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
    std::cout  << type << " " << name << ": \"I'm a robot ninja...\" (NinjaTrap destructor)" << std::endl;
}

void        NinjaTrap::ninjaShoebox(ClapTrap const &target)
{
    std::cout << "\"Take that!\" " << type << " " << name << " uses " << target.ClapTrap::type << " " << target.ClapTrap::name << "'s custom attack!" << std::endl;
}
        
void        NinjaTrap::ninjaShoebox(FragTrap const &target)
{
    std::cout << "\"Bop!\"       " << type << " " << name << " uses " << target.FragTrap::type << " " << target.FragTrap::name << "'s custom attack!" << std::endl;
}

void        NinjaTrap::ninjaShoebox(ScavTrap const &target)
{
    std::cout << "\"Hyah!\"      " << type << " " << name << " uses " << target.ScavTrap::type << " " << target.ScavTrap::name << "'s custom attack!" << std::endl;
}

void        NinjaTrap::ninjaShoebox(NinjaTrap const &target)
{
    std::cout << "\"Heyyah!\"    " << type << " " << name << " uses " << target.NinjaTrap::type << " " << target.NinjaTrap::name << "'s custom attack!" << std::endl;
}
