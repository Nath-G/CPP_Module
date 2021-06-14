/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:09:04 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/14 11:29:24 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
class Fixed
{
private:
    int                 _fixed_point_value;
    static int const    _fractionnal_bits_nb = 8;

public:
    Fixed(void);
    Fixed(Fixed const &copy);
    ~Fixed(void);
        Fixed   &operator=(Fixed const &rhs);
        int     getRawBits(void)const;
        void    setRawBits(int const raw);
};

#endif
