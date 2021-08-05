/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:38:39 by nagresel          #+#    #+#             */
/*   Updated: 2021/08/05 18:03:01 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main ()
{
    int a = 42, b = -102;
    float c = 0.5589, d = 0.5588, e = 1.5589, f = 2.5588;
    std::string str1 = "chaine1", str2 = "chaine2";
    std::cout << "a = " << a << " and b = " << b << " max(a, b) is ";
    std::cout << ::max<int>(a, b) << std::endl;
    std::cout << "c = " << c << " and d =" << d << " max(c, d) is ";
    std::cout << ::max<float>(c, d) << std::endl;
    std::cout << "max of min(" << c << ", " << d << ") and min(" << e << ", " << f << ") is ";
    std::cout << ::max <float> (::min<float>(c, d), ::min<float>(e, f)) << std::endl;
    std::cout << std::endl;
    std::cout << "a = " << a << " and b = " << b << " min(a, b) is ";
    std::cout << ::min<int>(a, b) << std::endl;
    std::cout << "c = " << c << " and d = " << d << " min(c, d) is ";
    std::cout << ::min<float>(c, d) << std::endl;
    std::cout << "min of the max(" << c << ", " << d << ") and the max(" << e << ", " << f << ") is ";
    std::cout << ::min <float> (::max<float>(c, d), ::max<float>(e, f)) << std::endl;
    std::cout << std::endl;
    std::cout << "str1 = " << str1 << " and str2 = " << str2 <<  " min(str1, str2) is ";
    std::cout << ::min <std::string> (str1, str2) << std::endl;
    std::cout << "max(str1, str2) is " << ::max <std::string> (str1, str2) << std::endl;
    std::cout << std::endl;
       
    std::cout << "Before swap a = " << a << " and b = " << b << std::endl;
    ::swap<int>(a, b);
    std::cout << "After swap  a = " << a << " and b = " << b << std::endl;
    std::cout << "Before swap e = " << e << " and f = " << f << std::endl;
    ::swap<float>(e, f);
    std::cout << "After swap  e = " << e << " and f = " << f << std::endl;
    std::cout << "Before swap  str1 = " << str1 << " and str2 = " << str2 << std::endl;
    ::swap<std::string>(str1, str2);
    std::cout << "After swap   str1 = " << str1 << " and str2 = " << str2 << std::endl;

}