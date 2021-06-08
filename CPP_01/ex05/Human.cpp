/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:12:53 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 10:30:28 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human()
{
}

Human::~Human()
{
}

std::string    Human::identify()
{
    return (this->_brain.identify());
}

Brain const     &Human::getBrain() const
{
    return (this->_brain);
}
 