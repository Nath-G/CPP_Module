/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:54:11 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/23 13:23:13 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap() : ClapTrap(), NinjaTrap(), FragTrap()
{
    this->ClapTrap::name = SuperTrap::name;
    this->ClapTrap::type = "SUP3R-TP";
    this->ClapTrap::_hit_points = this->FragTrap::_hit_points;
    this->ClapTrap::_max_hit_points = this->FragTrap::_max_hit_points;
    this->ClapTrap::_nrj_points = this->NinjaTrap::_nrj_points;
    this->ClapTrap::_max_nrj_points = this->NinjaTrap::_max_nrj_points;
    this->ClapTrap::_armor_damage_reduction = this->FragTrap::_armor_damage_reduction;
    this->ClapTrap::melee_damage = this->NinjaTrap::melee_damage;
    this->ClapTrap::ranged_damage = this->FragTrap::ranged_damage;
    std::cout << ClapTrap::type << " " << SuperTrap::name 
    << ": \"Let's get this party started!\" (SuperTrap constructor)"
    << std::endl;
}

SuperTrap::SuperTrap(std::string Name) : ClapTrap(Name), NinjaTrap(Name), FragTrap(Name)
{
    name = Name;
    this->ClapTrap::type = "SUP3R-TP";
    this->ClapTrap::_hit_points = this->FragTrap::_hit_points;
    this->ClapTrap::_max_hit_points = this->FragTrap::_max_hit_points;
    this->ClapTrap::_nrj_points = this->NinjaTrap::_nrj_points;
    this->ClapTrap::_max_nrj_points = this->NinjaTrap::_max_nrj_points;
    this->ClapTrap::_armor_damage_reduction = this->FragTrap::_armor_damage_reduction;
    this->ClapTrap::melee_damage = this->NinjaTrap::melee_damage;
    this->ClapTrap::ranged_damage = this->FragTrap::ranged_damage;
    std::cout << ClapTrap::type << " " << name 
    << ": \"Let's get this party started!\" (SuperTrap constructor)"
    << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &copy) : ClapTrap(copy)
{
    std::cout << ClapTrap::type << " Copy class from SuperTrap"<< std::endl;
}

SuperTrap::~SuperTrap(void)
{
    std::cout  << ClapTrap::type << " " << name << ": \"I'm a robot ninja...\" (SuperTrap destructor)" << std::endl;
}
