/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 12:41:35 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/16 20:21:19 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>

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

            FragTrap    &operator=(FragTrap const &rhs);
            void        rangedAttack(std::string const &target);
            void        meleeAttack(std::string const &target);
            void        takeDamage(unsigned int amount);
            void        beRepaired(unsigned int amount);
};

#endif
