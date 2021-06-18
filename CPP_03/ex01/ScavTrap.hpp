/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:24:23 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/18 15:47:09 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class ScavTrap
{
private:
            std::string     _name;
            unsigned int    _hit_points;
            unsigned int    _max_hit_points;
            unsigned int    _nrj_points;
            unsigned int    _max_nrj_points;
            unsigned int    _level;
            unsigned int    _armor_damage_reduction;
            
            void    initChallenges(void);
            void    (ScavTrap::*_challenges[4])(std::string const &target);
            void    pongBeerChallenge(std::string const &target);
            void    wetTshirtChallenge(std::string const &target);
            void    armWrestlingChallenge(std::string const &target);
            void    oneFeetChallenge(std::string const &target);

public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &copy);
        ~ScavTrap(void);
            
            unsigned int    melee_damage;
            unsigned int    ranged_damage;
            unsigned int    challenge_damage;

            ScavTrap    &operator=(ScavTrap const &rhs);

            void        rangedAttack(std::string const &target);
            void        meleeAttack(std::string const &target);
            void        takeDamage(unsigned int amount);
            void        beRepaired(unsigned int amount);
            void        challengeNewcomer(std::string const &target);
};

#endif