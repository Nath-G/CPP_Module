/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:24:53 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/21 14:20:43 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Jane Doe"), _hit_points(100), _max_hit_points(100),
                    _nrj_points(50), _max_nrj_points(50), _level(1),
                    _armor_damage_reduction(3), melee_damage(20),
                    ranged_damage(15), challenge_damage(10)
{
    std::cout  << "CL4P-TP "<< _name 
    << ": \"Glitching weirdness is a term of endearment, right?\""
    << std::endl;
    initChallenges();
    srand(time(NULL));
}

ClapTrap::ClapTrap(std::string Name): _name(Name), _hit_points(100), _max_hit_points(100),
                    _nrj_points(50), _max_nrj_points(50), _level(1),
                    _armor_damage_reduction(3), melee_damage(20),
                    ranged_damage(15), challenge_damage(10)
{
    std::cout << "CL4P-TP " << _name 
    << ": \"Glitching weirdness is a term of endearment, right?\""
    << std::endl;
    initChallenges();
    srand(time(NULL));
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
    *this = copy;
}

ClapTrap::~ClapTrap()

{
    std::cout  << "CL4P-TP " << _name << ": \"Meat confetti!\"" << std::endl;
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
    challenge_damage = rhs.challenge_damage;
    return (*this);
}

/*
void    ClapTrap::rangedAttack(std::string const &target)
{
    std::cout << "CL4P-TP " << _name << ": \"Save me from the Badass! (" << target << ") thanks to this attack at range, causing " << this->ranged_damage << " damage points.\"" << std::endl;
}
*/
void    ClapTrap::meleeAttack(std::string const &target)
{
    std::cout << "CL4P-TP " << _name << ": \"Bop! Ready for the PUNCHline?! I perform a Melee attack to " << target << " causing " << this->melee_damage << " damage points.\"" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    unsigned int damage = (amount > _armor_damage_reduction)  ? (amount - _armor_damage_reduction) : 0;
    _nrj_points = (damage < _nrj_points) ? (_nrj_points - damage) : 0;
    std::cout << "CL4P-TP " << _name << ": \"Ya feeling lucky, punk? I lose " << damage << " damage points (after reduction).\"" << std::endl;
    std::cout << _name << "'s Energy amount is now: " << _nrj_points << " points." << std::endl;
    if (_nrj_points <= 0)
    std::cout << _name << ": \"Oooh! Gigabits!\"" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    unsigned int repair = (amount + _nrj_points) < _max_nrj_points ? amount : (_max_nrj_points - _nrj_points);
    this->_nrj_points = (repair +_nrj_points);
    std::cout << "CL4P-TP " << _name << ": \"Sweet life juice! I'm repaired with " << repair << " points, "
    << "my Energy amount  is now: " << _nrj_points << " points.\"" << std::endl;
}

