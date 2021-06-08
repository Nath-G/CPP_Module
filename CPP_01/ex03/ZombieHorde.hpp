/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:13:04 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 13:25:10 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"

class ZombieHorde
{
private:
    Zombie      *_zombies;
    int         _zombieNb;
    std::string _names[10];

public:
    ZombieHorde(int n);
    ~ZombieHorde();
    void    announce() const;
};

#endif