/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:59:46 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/21 16:19:25 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
    this->_name = ClapTrap::_name;
    this->_type = "FR4G-TP";
    this->ClapTrap::_nrj_points = 100;
    this->ClapTrap::_max_nrj_points = 100;
    this->ClapTrap::_armor_damage_reduction = 5;
    this->ClapTrap::melee_damage = 30;
    this->ClapTrap::ranged_damage = 20;
    this->semicustom_damage = 45;
    std::cout << _type << " " << _name 
    << ": \"Hey everybody! Check out my package!\" (FraTrap constructor)" 
    << std::endl;
    srand(time(NULL));
}

FragTrap::FragTrap(std::string name) : ClapTrap()
{
    _name = name;
    this->_type = "FR4G-TP";
    this->ClapTrap::_nrj_points = 100;
    this->ClapTrap::_max_nrj_points = 100;
    this->ClapTrap::_armor_damage_reduction = 5;
    this->ClapTrap::melee_damage = 30;
    this->ClapTrap::ranged_damage = 20;
    this->semicustom_damage = 45;

    std::cout  << _type << " "<< _name 
    << ": \"Hey everybody! Check out my package!\" (FraTrap constructor)" 
    << std::endl;
    srand(time(NULL));
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
    std::cout  << _type << " Copy class from ClapTrap(copy)" << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << _type << " " << ClapTrap::_name << ": \"This is why I was built!\"(FragTrap destructor)" << std::endl;
}

void        FragTrap::vaulthunter_dot_exe(std::string const &target)
{
    if (_nrj_points < 25)
    {
        std::cout << _type << " " << _name << " is too tired to performs a semi-custom attacks ! He has to recover energy points before !" << std::endl;
        return ;
    }
    std::string attacks[5] = {
                                " pulls the antennas of ",
                                " puts Fingers in the eyes (or camera) of ",
                                " holws at death against ",
                                " trip ",
                                " pulls out a tooth from ",
    };
    _nrj_points = _nrj_points - 25;
    srand(time(NULL));
    std::cout << _type << " " << _name << attacks[std::rand() % 5] << target << std::endl;
    std::cout << _type << " " << _name << " has now " << this->_nrj_points << " energy points." << std::endl;
    return;

}
