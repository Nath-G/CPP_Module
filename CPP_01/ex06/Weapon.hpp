/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:57:12 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 16:36:33 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
private:
    std::string     &_refType;
    std::string     _type;

public:
    Weapon(std::string type);
    ~Weapon();
    
    const std::string     &getType(void) const;
    void            setType(std::string newType);
    void            setWeapon(void);
};

#endif
