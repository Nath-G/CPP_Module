/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:02:26 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/16 20:21:32 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): _name("Jane Doe"), _hit_points(100), _max_hit_points(100),
                    _nrj_points(100), _max_nrj_points(100), _level(1),
                    _armor_damage_reduction(5), melee_damage(30), ranged_damage(20)

{
    std::cout << "Default Constructor FragTrap " << _name << " called." << std::endl;
}

FragTrap::FragTrap(std::string Name): _name(Name), _hit_points(100),
                    _max_hit_points(100), _nrj_points(100), _max_nrj_points(100),
                    _level(1), _armor_damage_reduction(5), melee_damage(30), ranged_damage(20)

{
    std::cout << "Customize Constructor FragTrap " << _name << " called." << std::endl;

}

FragTrap::FragTrap(FragTrap const &copy)
{
    std::cout << "Copy FragTrap Constructor called." << std::endl;
    *this = copy;
}

FragTrap::~FragTrap()

{
    std::cout << "Destructor FragTrap called." << std::endl;

}

FragTrap    &FragTrap::operator=(FragTrap const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    _name = rhs._name;
    _hit_points = rhs._hit_points;
    _max_hit_points = rhs._max_hit_points;
    _nrj_points = rhs._nrj_points;
    _max_nrj_points = rhs._max_nrj_points;
    _level = rhs._level;
    melee_damage = rhs.melee_damage;
    ranged_damage = rhs.ranged_damage;
    _armor_damage_reduction = rhs._armor_damage_reduction;
    return (*this);
}

void    FragTrap::rangedAttack(std::string const &target)
{
    std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << this->ranged_damage << " damage points." << std::endl;
}

void    FragTrap::meleeAttack(std::string const &target)
{
    std::cout << "FR4G-TP " << _name << " performs a Melee attack to " << target << " causing " << this->melee_damage << " damage points." << std::endl;
}

void    FragTrap::takeDamage(unsigned int amount)
{
    unsigned int damage = (amount > _armor_damage_reduction)  ? (amount - _armor_damage_reduction) : 0;
    _nrj_points = (damage < _nrj_points) ? (_nrj_points - damage) : 0;
    std::cout << "FR4G-TP " << _name << " loses " << damage << " damage points (after reduction)." << std::endl;
    std::cout << _name << "'s Energy amount is now: " << _nrj_points << " points." << std::endl;
}

void    FragTrap::beRepaired(unsigned int amount)
{
    unsigned int repair = (amount + _nrj_points) < _max_nrj_points ? amount : (_max_nrj_points - _nrj_points);
    this->_nrj_points = (repair +_nrj_points);
    std::cout << "FR4G-TP " << _name << "is repaired with " << repair << " points." << std::endl;
    std::cout << "His Energy amount  is now: " << _nrj_points << " points." << std::endl;
}