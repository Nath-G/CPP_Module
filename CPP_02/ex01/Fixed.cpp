/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:14:16 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/14 16:35:20 by nagresel         ###   ########.fr       */
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

Fixed::Fixed(int const i)
{
    std::cout << "Int constructor called" << std::endl;
    _fixed_point_value = i << _fractionnal_bits_nb;
}
 
Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    float factor = 1 << _fractionnal_bits_nb;
    _fixed_point_value = (int)roundf(f * factor);
}

int     Fixed::toInt() const
{
    return(_fixed_point_value >> _fractionnal_bits_nb);
}

float   Fixed::toFloat() const
{
    float factor = 1 << _fractionnal_bits_nb;
    return(_fixed_point_value / factor);
}


std::ostream	&operator<<(std::ostream &ostream, Fixed const &rhs)
{
	ostream << rhs.toFloat();
	return (ostream);
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
