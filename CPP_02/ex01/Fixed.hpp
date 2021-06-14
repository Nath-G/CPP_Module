/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:09:04 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/14 16:52:09 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int                 _fixed_point_value;
    static int const    _fractionnal_bits_nb = 8;

public:
    Fixed(void);
    Fixed(Fixed const &copy);
    Fixed(int const i);
    Fixed(float const f);
    ~Fixed(void);
        Fixed   &operator=(Fixed const &rhs);
        int     getRawBits(void)const;
        void    setRawBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;
};

    std::ostream &operator<<(std::ostream &ostream, Fixed const &rhs);

#endif
