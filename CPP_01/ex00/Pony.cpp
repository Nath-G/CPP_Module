/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:54:46 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/04 16:30:38 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string const &Name,
            std::string const &Race,
            std::string const &Color,
            std::string const &Size,
            std::string const &Favorite_Meal):
            _name(Name),
            _race(Race),
            _color(Color),
            _size(Size),
            _favorite_meal(Favorite_Meal)
{
    std::cout << this->_name << " is born !" << std::endl;
    return;
}

void Pony::show_up(void)
{
    std::cout << this->_name << " shows up at the start of the race, he's a "
        << this->_color << " " << this->_race << " pony and sizes "
        << this->_size << " meter at the whithers."<< std::endl;
}

void    Pony::run(void)
{
    std::cout << this->_name << " is running." << std::endl;

}

void    Pony::cry(void)
{
    std::cout << this->_name << "'s run a lot, so he wants a gift now." << std::endl;
}

void    Pony::eat(void)
{
    std::cout  << this->_favorite_meal << " is " <<   this->_name << "'s favorite meal, thanks a lot !" << std::endl;
}

Pony::~Pony(void)
{
    std::cout << this->_name << " is dead !" << std::endl;
    return;
}