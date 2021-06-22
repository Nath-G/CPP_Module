/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:24:53 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/21 14:18:53 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(): ClapTrap_name(), ("Jane Doe"), _hit_points(100), _max_hit_points(100),
                    _nrj_points(50), _max_nrj_points(50), _level(1),
                    _armor_damage_reduction(3), melee_damage(20),
                    ranged_damage(15), challenge_damage(10)
{
    std::cout  << "SC4V-TP "<< _name 
    << ": \"Oups Glitching weirdness is a term of endearment, right?\""
    << std::endl;
    initChallenges();
    srand(time(NULL));
}

ScavTrap::ScavTrap(std::string Name): _name(Name), _hit_points(100), _max_hit_points(100),
                    _nrj_points(50), _max_nrj_points(50), _level(1),
                    _armor_damage_reduction(3), melee_damage(20),
                    ranged_damage(15), challenge_damage(10)
{
    std::cout << "SC4V-TP " << _name 
    << ": \"Glitching weirdness is a term of endearment, right?\""
    << std::endl;
    initChallenges();
    srand(time(NULL));
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
    *this = copy;
}

ScavTrap::~ScavTrap()

{
    std::cout  << "SC4V-TP " << _name << ": \"Meat confetti!\"" << std::endl;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &rhs)
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

void    ScavTrap::initChallenges()
{
    this->_challenges[0] = &ScavTrap::pongBeerChallenge;
    this->_challenges[1] = &ScavTrap::wetTshirtChallenge;
    this->_challenges[2] = &ScavTrap::armWrestlingChallenge;
    this->_challenges[3] = &ScavTrap::oneFeetChallenge;

}

void    ScavTrap::rangedAttack(std::string const &target)
{
    std::cout << "SC4V-TP " << _name << ": \"Save me from the Badass! (" << target << ") thanks to this attack at range, causing " << this->ranged_damage << " damage points.\"" << std::endl;
}

void    ScavTrap::meleeAttack(std::string const &target)
{
    std::cout << "SC4V-TP " << _name << ": \"Bop! Ready for the PUNCHline?! I perform a Melee attack to " << target << " causing " << this->melee_damage << " damage points.\"" << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount)
{
    unsigned int damage = (amount > _armor_damage_reduction)  ? (amount - _armor_damage_reduction) : 0;
    _nrj_points = (damage < _nrj_points) ? (_nrj_points - damage) : 0;
    std::cout << "SC4V-TP " << _name << ": \"Ya feeling lucky, punk? I lose " << damage << " damage points (after reduction).\"" << std::endl;
    std::cout << _name << "'s Energy amount is now: " << _nrj_points << " points." << std::endl;
    if (_nrj_points <= 0)
    std::cout << _name << ": \"Oooh! Gigabits!\"" << std::endl;
}

void    ScavTrap::beRepaired(unsigned int amount)
{
    unsigned int repair = (amount + _nrj_points) < _max_nrj_points ? amount : (_max_nrj_points - _nrj_points);
    this->_nrj_points = (repair +_nrj_points);
    std::cout << "SC4V-TP " << _name << ": \"Sweet life juice! I'm repaired with " << repair << " points, "
    << "my Energy amount  is now: " << _nrj_points << " points.\"" << std::endl;
}

void    ScavTrap::challengeNewcomer(std::string const &target)
{
    srand(time(NULL));
    (this->*_challenges[rand() % 4])(target);
    return;
}

void    ScavTrap::pongBeerChallenge(std::string const &target)
{
    std::cout << "SC4V-TP " << _name << ": \"Bop! Ready for the PONG BEER " << target << " ?!!! \""<< std::endl;
}

void    ScavTrap::wetTshirtChallenge(std::string const &target)
{
    std::cout << "SC4V-TP " << _name << ": \"RUN FOR YOUR LIIIIIVES! or perform a WET T-SHIRT contest " << target << " ?!!! \""<< std::endl;
}

void    ScavTrap::armWrestlingChallenge(std::string const &target)
{
    std::cout << "SC4V-TP " << _name << ": \"Look out, a Badass! Arm Wrestling contest," << target << " ?!!! \""<< std::endl;
}

void    ScavTrap::oneFeetChallenge(std::string const &target)
{
    std::cout << "SC4V-TP " << _name << ": \"Boiyoiyoiyoiyoing! I'm sure I can stay one one feet more time than you," << target << " ?!!! \""<< std::endl;
}

