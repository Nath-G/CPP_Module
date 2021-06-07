/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:31:43 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/07 12:32:57 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieEvent
{
    private:
        std::string _type;
        std::string _names[10];


    public:
        
        ZombieEvent(void);
        ~ZombieEvent(void);
        void    setZombieType(std::string _type);
        Zombie* newZombie(std::string _name);
        void    randomChump(void);
};

#endif