/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:53:34 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/23 18:02:45 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src) 
{
    *this = src;
}

Intern::~Intern()
{
}

Intern  &Intern::operator=(const Intern &rhs)
{
    if (this == &rhs)
        return(*this);
    return(*this);
}

Form    *Intern::makeForm(const std::string &formName, const std::string &target)const
{
    ShrubberyCreationForm   shrub(target);
    PresidentialPardonForm  pres(target);
    RobotomyRequestForm     rob(target);
    Form                    *formTab[] = {&shrub, &pres, &rob};
    for (int i = 0; i < 3; i++)
    {
        if (formTab[i]->getName() == formName)
        {
            std::cout << "Intern creates " << formName << "." << std::endl;
            return (formTab[i]->clone());
        }
    }
    throw FormUnknownException();
    return (NULL);
}

const char  *Intern::FormUnknownException::what() const throw()
{
    return ("Unknown Form Name Exception");
}
