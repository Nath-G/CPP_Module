/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:58:18 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/21 15:35:18 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include <iostream>
# include <cstdlib>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class NinjaTrap : public ClapTrap
{
    
private:
protected:
public:
    NinjaTrap();
    NinjaTrap(std::string name);
    NinjaTrap(NinjaTrap const &copy);
    ~NinjaTrap(void);

        NinjaTrap        &operator=(NinjaTrap const &rhs);

        void        ninjaShoebox(ClapTrap const &target);
        void        ninjaShoebox(FragTrap const &target);
        void        ninjaShoebox(ScavTrap const &target);
        void        ninjaShoebox(NinjaTrap const &target);

};

#endif
