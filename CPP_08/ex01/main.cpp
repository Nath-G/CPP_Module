/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:49:07 by nagresel          #+#    #+#             */
/*   Updated: 2021/09/22 17:10:18 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <ctime>
# define GREY	"[90m"
# define C_RES	"[0m"


void  test_notEnoughElement()
{
   std::cout << GREY << "*** TEST NOT ENOUGH ELEMENTS ***" << C_RES << std::endl;
  Span sp(1);
  sp.addNumber(5);
 
  std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
  std::cout << "longest span = " << sp.longestSpan() << std::endl;
}

int s_random()
{
	return (std::rand() % 1000000);
}

void test_10k_values()
{
	std::cout << GREY << "*** TEST span 10k values randomized with 1 000k***" << C_RES << std::endl;

	std::srand(unsigned(std::time(NULL)));
	std::vector<int> board(10000);
	std::generate(board.begin(), board.end(), s_random);

	Span sp = Span(10000);
	sp.addNumber(board.begin(), board.end());
	std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "longest span = " << sp.longestSpan() << std::endl;
  std::cout << std::endl;
}

void  test_subject()
{
  std::cout << GREY << "*** TEST SUBJECT ***" << C_RES << std::endl;
  Span sp(5);
  sp.addNumber(5);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
  std::cout << "longest span = " << sp.longestSpan() << std::endl;
  std::cout << std::endl;
}

void  test_limits()
{
  std::cout << GREY << "*** TEST LIMITS***" << C_RES << std::endl;
  Span sp(5);
  sp.addNumber(2);
  sp.addNumber(2147483647);
  sp.addNumber(-17);
  sp.addNumber(9);
  sp.addNumber(-2147483648);
  std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
  std::cout << "longest span = " << sp.longestSpan() << std::endl;
  std::cout << std::endl;
}

int main()
{
  try
  {
    test_notEnoughElement();
  }
  catch(std::exception & e) { std::cout << e.what() << std::endl; }
  std::cout << std::endl;
  try
  {
    test_subject();
    std::cin.get();
    test_limits();
    std::cin.get();
    test_10k_values();
  }
  catch(std::exception & e) { std::cout << e.what() << std::endl; }
    return(0);
}