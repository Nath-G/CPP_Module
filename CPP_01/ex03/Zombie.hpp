/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:32:16 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 10:16:53 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie
{
    private:
        std::string _type;
        std::string _name;

    public:
        Zombie();
        Zombie(std::string type, std::string name);
        ~Zombie();
    
        void    announce() const;
        void    setType(std::string type);
        void    setName(std::string name);

};

#endif