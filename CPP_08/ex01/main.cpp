/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:49:07 by nagresel          #+#    #+#             */
/*   Updated: 2021/09/17 18:50:26 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
    Span sp(5);
    sp.addNumber(45);
    sp.addNumber(-45);
    sp.addNumber(0);
    sp.addNumber(45000);
    sp.addNumber(-4500000);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  //  sp.longestSpan();
    
    return(0);
}