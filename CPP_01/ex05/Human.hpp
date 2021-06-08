/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:02:06 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 12:10:31 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include <sstream>
# include <iostream>
# include "Brain.hpp"

class Human
{
private:
    Brain const _brain;

public:
    Human(void);
    ~Human(void);
    
    std::string    identify();
    Brain const     &getBrain() const;

};

#endif