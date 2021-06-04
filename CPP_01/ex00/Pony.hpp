/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:27:29 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/04 16:28:06 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <string>
# include <iostream>

class Pony
{
private:

    std::string const &_name;
    std::string const &_race;
    std::string const &_color;
    std::string const &_size;
    std::string const &_favorite_meal;


public:
    Pony();
    Pony(std::string const &Name, std::string const &Race,
    std::string const &Color, std::string const &Size, std::string const &Favorite_meal);
    ~Pony(void);

    void    show_up(void);
    void    run(void);
    void    cry(void);
    void    eat(void);
};

#endif
