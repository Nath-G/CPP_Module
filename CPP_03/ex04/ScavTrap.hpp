/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:58:18 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/23 18:21:16 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
        void    initChallenges(void);
        void    (ScavTrap::*_challenges[4])(std::string const &target);
        void    pongBeerChallenge(std::string const &target);
        void    wetTshirtChallenge(std::string const &target);
        void    armWrestlingChallenge(std::string const &target);
        void    oneFeetChallenge(std::string const &target);
protected:
public:
    ScavTrap();
    ScavTrap(std::string Name);
    ScavTrap(ScavTrap const &copy);
    ~ScavTrap(void);

        ScavTrap        &operator=(ScavTrap const &rhs);

        unsigned int   challenge_damage;// = 45;

        void        challengeNewcomer(std::string const &target);
};

#endif
