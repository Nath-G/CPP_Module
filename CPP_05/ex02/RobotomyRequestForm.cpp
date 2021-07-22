/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:19:41 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/22 17:48:25 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("Robotomy request form", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src.getName(), 72, 45, src.getTarget())
{
    *this = src;
    this->Form::setIsSigned(0);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    this->Form::setIsSigned(rhs.getIsSigned());
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor)
{
    Form::execute(executor);
    std::cout << "*** Drill noise ***" << std::endl;
    if (rand() %2)
        std::cout << this->getTarget() << " has been robotomized." << std::endl;
    else
        std::cout << this->getTarget() << " has NOT been robotomized : FAILURE." << std::endl;
}
