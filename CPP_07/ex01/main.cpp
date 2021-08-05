/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:16:17 by nagresel          #+#    #+#             */
/*   Updated: 2021/08/05 19:02:39 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


int main()
{
    int lol[] = {1, 2, 3, -888, 20, 99};
    char oups[] = {41, 42, 53, 64, 120, 99};
    std::string str = "chaine1";
    std::string str1 = "";
    iter(lol, 6, &display);
    iter(oups, 6, &display);
    iter(&str, 1, &display);
    iter(&str1, 1, &display);
}