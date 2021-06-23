/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 11:54:50 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/23 13:20:48 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <string>
# include <iostream>
//# include <cstdlib>

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
//#include "SuperTrap.hpp"


class SuperTrap : public NinjaTrap, public FragTrap
{
    
private:
protected:
public:
    SuperTrap();
    SuperTrap(std::string Name);
    SuperTrap(SuperTrap const &copy);
    ~SuperTrap(void);

        SuperTrap        &operator=(SuperTrap const &rhs);
};

#endif
