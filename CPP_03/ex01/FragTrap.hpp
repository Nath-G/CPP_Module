/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:41:35 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/18 11:57:35 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>

class FragTrap
{

    private:
            std::string     _name;
            unsigned int    _hit_points;
            unsigned int    _max_hit_points;
            unsigned int    _nrj_points;
            unsigned int    _max_nrj_points;
            unsigned int    _level;
            unsigned int    _armor_damage_reduction;

    public:
        FragTrap(void);
        FragTrap(std::string Name);
        FragTrap(FragTrap const &copy);
        ~FragTrap(void);

            unsigned int    melee_damage;
            unsigned int    ranged_damage;
            unsigned int    semicustom_damage;

            FragTrap        &operator=(FragTrap const &rhs);

            void            rangedAttack(std::string const &target);
            void            meleeAttack(std::string const &target);
            void            takeDamage(unsigned int amount);
            void            beRepaired(unsigned int amount);
            void            vaulthunter_dot_exe(std::string const &target);
};

#endif
