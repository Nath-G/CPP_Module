/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:06:01 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/08 12:02:04 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
Brain::Brain() : _hemisphereLeft(1), _hemisphereRight(1),  _corpusCallosum(1)
{
    std::stringstream   ptrAddress;

    ptrAddress << this;
    this->_address = ptrAddress.str();
}

Brain::~Brain()
{
}

int    Brain::getHemisphereLeft(void)
{
    return(this->_hemisphereLeft);
}

int    Brain::getHemisphereRight(void)
{
    return(this->_hemisphereRight);
}

int    Brain::getCorpusCallosum(void)
{
    return(this->_corpusCallosum);
}

std::string     Brain::identify() const
{
    return (this->_address);
}

