/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:19:41 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/22 10:52:34 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
RobotomyRequestForm::RobotomyRequestForm() : Form("Shrubbery", 145, 137)
{
}*/

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("Robotomy request", 72, 45, target)
{
 //   this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src.getName(), 145, 137, src.getTarget())
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



std::string     RobotomyRequestForm::getShrubbery() const
{
    return (this->getTarget());
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!(this->getIsSigned()))
        throw FormUnsignedException();
    if (executor.getGrade() > this->getExecGradeRequired())
        throw GradeTooLowException();
    std::cout << "*** Drill noise ***" << std::endl;
    if (rand() %2)
        std::cout << this->getTarget() << " has been robotomized." << std::endl;
    else
        throw RobotomizedException();
   
}

const char  *RobotomyRequestForm::RobotomizedException::what() const throw()
{
    return ("Robotomization Error.");
}
