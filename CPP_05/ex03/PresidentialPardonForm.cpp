/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:19:41 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/22 10:52:34 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("presidential pardon", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form(src.getName(), 25, 5, src.getTarget())
{
    *this = src;
    this->Form::setIsSigned(0);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    this->Form::setIsSigned(rhs.getIsSigned());
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor)
{
    Form::execute(executor);
    std::cout << this->getTarget() << " has been forgiven by Zafod Beeblebrox." << std::endl;
}

Form    *PresidentialPardonForm::clone()const
{
    return (new PresidentialPardonForm(this->getTarget()));
}
