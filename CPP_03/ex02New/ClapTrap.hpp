/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 10:24:23 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/21 14:14:47 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class ClapTrap
{
protected:
            std::string     _name;
            unsigned int    _hit_points;
            unsigned int    _max_hit_points;
            unsigned int    _nrj_points;
            unsigned int    _max_nrj_points;
            unsigned int    _level;
            unsigned int    _armor_damage_reduction;
            

public:
        ClapTrap(void);
    //    ClapTrap(std::string name);
        ClapTrap(ClapTrap const &copy);
        ~ClapTrap(void);
            
            unsigned int    melee_damage;
            unsigned int    ranged_damage;
        //   unsigned int    challenge_damage;

            ClapTrap    &operator=(ClapTrap const &rhs);

            void        rangedAttack(std::string const &target);
            void        meleeAttack(std::string const &target);
            void        takeDamage(unsigned int amount);
            void        beRepaired(unsigned int amount);
        //    void        challengeNewcomer(std::string const &target);
};

#endif