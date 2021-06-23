/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:01:38 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/23 18:26:12 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int     main()
{
    FragTrap B4RBOT("B4R-BOT");
    ScavTrap H010TP("H010-TP");
    
    std::cout << std::endl;

    H010TP.challengeNewcomer("B4R-BOT");
    std::cout << std::endl;

    B4RBOT.meleeAttack("H010-TP");
    H010TP.takeDamage(B4RBOT.melee_damage);
    std::cout << std::endl;
        
    H010TP.rangedAttack("B4R-BOT");
    B4RBOT.takeDamage(B4RBOT.ranged_damage);
    std::cout << std::endl;
        
    B4RBOT.vaulthunter_dot_exe("H010-TP");
    H010TP.takeDamage(B4RBOT.semicustom_damage);
    std::cout << std::endl;
        
    ScavTrap DANTRP("DAN-TRP");
    B4RBOT.vaulthunter_dot_exe("DAN-TRP");
    DANTRP.takeDamage(B4RBOT.semicustom_damage);
    std::cout << std::endl;
    
    DANTRP.beRepaired(30);
    DANTRP.beRepaired(30);
    std::cout << std::endl;

    B4RBOT.vaulthunter_dot_exe("DAN-TRP");
    DANTRP.takeDamage(B4RBOT.semicustom_damage);
    std::cout << std::endl;

    DANTRP.meleeAttack("B4R-BOT");
    B4RBOT.takeDamage(DANTRP.melee_damage);

    std::cout << std::endl;
}
