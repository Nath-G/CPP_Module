/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:01:38 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/16 20:21:35 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int     main()
{
    FragTrap oups("Oups");
    FragTrap coco("Coco");
    
    //oups.takeDamage(50);
            oups.rangedAttack("Coco");
            coco.takeDamage(oups.ranged_damage);
            coco.rangedAttack("Oups");
            oups.takeDamage(oups.ranged_damage);
            oups.meleeAttack("Coco");
            coco.takeDamage(20);

            oups.meleeAttack("Coco");
            oups.meleeAttack("Coco");
            oups.meleeAttack("Coco");
            oups.meleeAttack("Coco");
            coco.meleeAttack("Oups");
            oups.beRepaired(50);
            coco.meleeAttack("Oups");

            

 //   oups.beRepaired(50);
}
