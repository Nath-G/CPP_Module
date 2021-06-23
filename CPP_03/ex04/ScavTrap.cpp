/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:59:46 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/23 13:24:04 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
    this->name = ClapTrap::name;
    this->type = "SC4V-TP";
    this->ClapTrap::_nrj_points = 50;
    this->ClapTrap::_max_nrj_points = 50;
    this->ClapTrap::_armor_damage_reduction = 3;
    this->ClapTrap::melee_damage = 20;
    this->ClapTrap::ranged_damage = 15;
    this->challenge_damage = 10;
    std::cout  << type << " " << name 
    << ": \"Glitching weirdness is a term of endearment, right?\" (ScavTrap constructor)"
    << std::endl;
    srand(time(NULL));
    initChallenges();
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    this->ClapTrap::name = Name;
    this->ClapTrap::type = "SC4V-TP";
    this->ClapTrap::_nrj_points = 50;
    this->ClapTrap::_max_nrj_points = 50;
    this->ClapTrap::_armor_damage_reduction = 3;
    this->ClapTrap::melee_damage = 20;
    this->ClapTrap::ranged_damage = 15;
    this->challenge_damage = 10;
    std::cout << type << " " << name 
    << ": \"Glitching weirdness is a term of endearment, right?\" (ScavTrap constructor)"
    << std::endl;
    srand(time(NULL));
    initChallenges();
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy)
{
    std::cout << type << " Copy class from ScavTrap(copy)"<< std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout  << type << " " << name << ": \"Meat confetti!\" (ScavTrap destructor)" << std::endl;
}

void    ScavTrap::initChallenges()
{
    this->_challenges[0] = &ScavTrap::pongBeerChallenge;
    this->_challenges[1] = &ScavTrap::wetTshirtChallenge;
    this->_challenges[2] = &ScavTrap::armWrestlingChallenge;
    this->_challenges[3] = &ScavTrap::oneFeetChallenge;

}

void    ScavTrap::challengeNewcomer(std::string const &target)
{
    srand(time(NULL));
    (this->*_challenges[rand() % 4])(target);
    return;
}

void    ScavTrap::pongBeerChallenge(std::string const &target)
{
    std::cout << type << " " << name << ": \"Bop! Ready for the PONG BEER " << target << " ?!!! \""<< std::endl;
}

void    ScavTrap::wetTshirtChallenge(std::string const &target)
{
    std::cout << type << " " << name << ": \"RUN FOR YOUR LIIIIIVES! or perform a WET T-SHIRT contest " << target << " ?!!! \""<< std::endl;
}

void    ScavTrap::armWrestlingChallenge(std::string const &target)
{
    std::cout << type << " " << name << ": \"Look out, a Badass! Arm Wrestling contest," << target << " ?!!! \""<< std::endl;
}

void    ScavTrap::oneFeetChallenge(std::string const &target)
{
    std::cout << type << " " << name << ": \"Boiyoiyoiyoiyoing! I'm sure I can stay one one feet more time than you," << target << " ?!!! \""<< std::endl;
}
