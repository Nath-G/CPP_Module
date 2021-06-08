/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:39:56 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 15:53:37 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
        std::string     _name;
        Weapon          &_weapon;
public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();

        void            attack();
};

#endif