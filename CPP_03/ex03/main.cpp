/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:01:38 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/23 18:17:17 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int     main()
{
    std::cout << "------------------------------------------------" << std::endl;
    
    FragTrap B4RBOT("B4R-BOT");
    ScavTrap H010TP("H010-TP");

    std::cout << "------------------------------------------------" << std::endl;
    
    std::cout << std::endl;

    H010TP.challengeNewcomer("B4R-BOT");
    std::cout << std::endl;

    B4RBOT.meleeAttack("H010-TP");
    H010TP.takeDamage(B4RBOT.melee_damage);
    std::cout << std::endl;
        
    H010TP.rangedAttack("B4R-BOT");
    B4RBOT.takeDamage(H010TP.ranged_damage);
    std::cout << std::endl;
        
    B4RBOT.vaulthunter_dot_exe("H010-TP");
    H010TP.takeDamage(B4RBOT.semicustom_damage);
    std::cout << std::endl;

    std::cout << "------------------------------------------------" << std::endl;
    ScavTrap DANTRP("DAN-TRP");
    std::cout << "------------------------------------------------" << std::endl;

    B4RBOT.vaulthunter_dot_exe("DAN-TRP");
    DANTRP.takeDamage(B4RBOT.semicustom_damage);
    std::cout << std::endl;
    
    DANTRP.beRepaired(30);
    DANTRP.beRepaired(30);
    std::cout << std::endl;

    B4RBOT.vaulthunter_dot_exe("DAN-TRP");
    DANTRP.takeDamage(B4RBOT.semicustom_damage);
    std::cout << std::endl;

    B4RBOT.beRepaired(50);
    std::cout << std::endl;
    
    DANTRP.meleeAttack("B4R-BOT");
    B4RBOT.takeDamage(DANTRP.melee_damage);
    std::cout << std::endl;

    /*Ninja Attaque */
    std::cout << "------------------------------------------------" << std::endl;

    NinjaTrap NINJATP("N1NJ4-TP");
    NinjaTrap CHIYOME("CH1YOME");
    ClapTrap CLAPPY;

    std::cout << "------------------------------------------------" << std::endl;
    std::cout << std::endl;

    CHIYOME.ninjaShoebox(B4RBOT);
    CHIYOME.ninjaShoebox(CLAPPY);
    CHIYOME.ninjaShoebox(DANTRP);
    CHIYOME.ninjaShoebox(NINJATP);
    std::cout << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

}
