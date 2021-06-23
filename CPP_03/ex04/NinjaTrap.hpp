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
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class NinjaTrap : public virtual ClapTrap
{
private:

protected:
        const static int     _nrj_points = 120;
        const static int     _max_nrj_points = 120;
public:
    NinjaTrap();
    NinjaTrap(std::string Name);
    NinjaTrap(NinjaTrap const &copy);
    ~NinjaTrap(void);

        NinjaTrap        &operator=(NinjaTrap const &rhs);

        const static int     melee_damage = 60;
        
        void        ninjaShoebox(ClapTrap const &target);
        void        ninjaShoebox(FragTrap const &target);
        void        ninjaShoebox(ScavTrap const &target);
        void        ninjaShoebox(NinjaTrap const &target);
};

#endif
