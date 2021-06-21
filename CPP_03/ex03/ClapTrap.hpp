/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:41:35 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/21 19:00:41 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class ClapTrap
{

    private:
    protected:
            std::string     _name;
     //       std::string     _type;
            unsigned int    _hit_points;
            unsigned int    _max_hit_points;
            unsigned int    _nrj_points;
            unsigned int    _max_nrj_points;
            unsigned int    _level;
            unsigned int    _armor_damage_reduction;


    public:
        ClapTrap();
    //    ClapTrap(std::string name);
        ClapTrap(ClapTrap const &copy);
        ~ClapTrap(void);

            unsigned int    melee_damage;
            unsigned int    ranged_damage;
            std::string     _type;

            ClapTrap        &operator=(ClapTrap const &rhs);

            void            rangedAttack(std::string const &target);
            void            meleeAttack(std::string const &target);
            void            takeDamage(unsigned int amount);
            void            beRepaired(unsigned int amount);
};

#endif
