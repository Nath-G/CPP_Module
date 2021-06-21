/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:02:26 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/21 18:56:52 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Clappy"), _type("CL4V-TP")
{
    _hit_points = 100;
    _max_hit_points = 100;
    _nrj_points = 0;
    _max_nrj_points = 0;
    _level = 1;
    _armor_damage_reduction = 0;
    melee_damage = 0;
    ranged_damage = 0;
    std::cout << _type << " " << _name 
    << ": \"Directive one: Protect humanity! Directive two: Obey Jack at all costs. Directive three: Dance!\"" 
    << std::endl << "Jack: \"No no no no! Cancel directive three!\""
    << std::endl << _type << " " << _name << ": \"Commencing directive three! Uhntssuhntssuhntss--\""
    << std::endl << "Jack: \"Ugh, friggin' hate that guy.\" (ClapTrap constructor)"
    << std::endl;
    srand(time(NULL));
}

ClapTrap::ClapTrap(ClapTrap const &copy) : _name("Clappy std")
{
    std::cout  << _type << " ClapTrap Copy class "<< std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap()

{
    std::cout << _type << " " << _name << ": \"Ooh, squishy bits!\" (ClapTrap destructor)" << std::endl;
}

ClapTrap    &ClapTrap::operator=(ClapTrap const &rhs)
{
    _name = rhs._name;
    _hit_points = rhs._hit_points;
    _max_hit_points = rhs._max_hit_points;
    _nrj_points = rhs._nrj_points;
    _max_nrj_points = rhs._max_nrj_points;
    _level = rhs._level;
    melee_damage = rhs.melee_damage;
    ranged_damage = rhs.ranged_damage;
    _armor_damage_reduction = rhs._armor_damage_reduction;
    _type = rhs._type;
    return (*this);
}

void    ClapTrap::rangedAttack(std::string const &target)
{
    std::cout << _type << " " << _name << " attacks " << target << " at range, causing " << this->ranged_damage << " damage points." << std::endl;
}

void    ClapTrap::meleeAttack(std::string const &target)
{
    std::cout << _type << " " << _name << " performs a Melee attack to " << target << " causing " << this->melee_damage << " damage points." << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    unsigned int damage = (amount > _armor_damage_reduction)  ? (amount - _armor_damage_reduction) : 0;
    _nrj_points = (damage < _nrj_points) ? (_nrj_points - damage) : 0;
    std::cout << _type << " " << _name << " loses " << damage << " damage points (after reduction)." << std::endl;
    std::cout << _type << " " << _name << "'s Energy amount is now: " << _nrj_points << " points." << std::endl;
    if (_nrj_points <= 0)
    std::cout << _type << " " << _name << ": \"I'm dead I'm dead, Oh my god! I'm dead.\"" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    unsigned int repair = (amount + _nrj_points) < _max_nrj_points ? amount : (_max_nrj_points - _nrj_points);
    this->_nrj_points = (repair +_nrj_points);
    std::cout << _type << " " << _name << " is repaired with " << repair << " points." << std::endl;
    std::cout << "His Energy amount  is now: " << _nrj_points << " points." << std::endl;
}
