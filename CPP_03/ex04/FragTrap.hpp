/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:58:18 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/23 13:21:31 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    
private:
protected:
public:
    FragTrap();
    FragTrap(std::string Name);
    FragTrap(FragTrap const &copy);
    ~FragTrap(void);

        FragTrap        &operator=(FragTrap const &rhs);

        unsigned int   semicustom_damage;// = 45;

        void            vaulthunter_dot_exe(std::string const &target);
};

#endif
