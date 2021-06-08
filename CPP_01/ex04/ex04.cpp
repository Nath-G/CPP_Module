/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:40:21 by nagresel          #+#    #+#             */
/*   Updated: 2021/06/07 18:53:58 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *ptr = &string;
    std::string &ref = string;
    
    std::cout << "ptr sur string = '" << *ptr << "'" << std::endl;
    std::cout << "ref sur string = '" << ref << "'" << std::endl;    
}