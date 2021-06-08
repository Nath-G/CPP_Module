/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:39:56 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 16:30:34 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
        std::string     _name;
        Weapon          *_weapon;
public:
        HumanB(std::string name);
        ~HumanB();

        void            attack();
        void            setWeapon(Weapon weapon);

};

#endif