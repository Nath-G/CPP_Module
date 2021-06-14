/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:14:16 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/14 15:14:24 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixed_point_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    
}

Fixed   &Fixed::operator=(Fixed const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_fixed_point_value = rhs.getRawBits();
    return (*this);
}

int     Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixed_point_value);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixed_point_value = raw;
}
