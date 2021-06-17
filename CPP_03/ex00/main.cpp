/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:01:38 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/17 18:43:23 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int     main()
{
    FragTrap B4RBOT("B4R-BOT");
    FragTrap H010TP("H010-TP");
    FragTrap SHADOWTRP("5HADOW-TRP");
    FragTrap DANTRP("DAN-TRP");
    FragTrap VRON1CA("VR-ON1CA");

    std::cout << std::endl;

    B4RBOT.rangedAttack("H010-TP");
    H010TP.takeDamage(B4RBOT.ranged_damage);
    std::cout << std::endl;
        
    H010TP.rangedAttack("B4R-BOT");
    B4RBOT.takeDamage(B4RBOT.ranged_damage);
    std::cout << std::endl;
        
    B4RBOT.vaulthunter_dot_exe("H010-TP");
    H010TP.takeDamage(B4RBOT.semicustom_damage);
    std::cout << std::endl;
        
    B4RBOT.meleeAttack("H010-TP");
    H010TP.takeDamage(B4RBOT.melee_damage);
    std::cout << std::endl;
        
    B4RBOT.meleeAttack("H010-TP");
    H010TP.takeDamage(B4RBOT.melee_damage);
    std::cout << std::endl;
        
    B4RBOT.rangedAttack("H010-TP");
    H010TP.takeDamage(B4RBOT.ranged_damage);
    std::cout << std::endl;

    B4RBOT.vaulthunter_dot_exe("DAN-TRP");
    DANTRP.takeDamage(B4RBOT.semicustom_damage);
    std::cout << std::endl;
        
    B4RBOT.vaulthunter_dot_exe("DAN-TRP");
    DANTRP.takeDamage(B4RBOT.semicustom_damage);
    std::cout << std::endl;
        
    B4RBOT.vaulthunter_dot_exe("5HADOW-TRP");
    std::cout << std::endl;

    VRON1CA.vaulthunter_dot_exe("5HADOW-TRP");
    SHADOWTRP.takeDamage(VRON1CA.semicustom_damage);
    std::cout << std::endl;
        
    DANTRP.vaulthunter_dot_exe("5HADOW-TRP");
    std::cout << std::endl;
            
    DANTRP.beRepaired(50);
    std::cout << std::endl;

    DANTRP.vaulthunter_dot_exe("VR-ON1CA");
    VRON1CA.takeDamage(DANTRP.semicustom_damage);
    std::cout << std::endl;
    
}
