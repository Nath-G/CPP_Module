/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:56:37 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/22 18:12:40 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Someone in the matrix"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
    checkGradeValue(_grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    this->_name = rhs.getName();
    this->_grade = rhs.getGrade();
    return (*this);
}

std::string     Bureaucrat::getName() const
{
    return(_name);
}

void        Bureaucrat::setName(std::string const name)
{
    this->_name = name;
}

int         Bureaucrat::getGrade() const
{
    return(this->_grade);
}

void        Bureaucrat::setGrade(int grade)
{
    this->_grade = grade;
}

void        Bureaucrat::incrementGrade()
{
    checkGradeValue(_grade - 1);
    _grade = _grade - 1;
}

void        Bureaucrat::decrementGrade()
{
    checkGradeValue(_grade + 1);
    _grade = _grade + 1;
}


void        Bureaucrat::checkGradeValue(int gradeValue)
{
    if (gradeValue < 1)
        throw Bureaucrat::GradeTooHighException();
    if (gradeValue > 150)
        throw Bureaucrat::GradeTooLowException();
}

void        Bureaucrat::signForm(Form &form) const
{
    if(form.getIsSigned())
        std::cout << getName() << " can not sign because " << form.getName() << " is already signed." << std::endl;
    else
    {
        try
        {
            form.beSigned(*this);
            std::cout << _name << " signs " << form.getName() << "." << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cout << _name << " can not sign " << form.getName() << " because " << e.what() << std::endl;
        }
    }
}


void        Bureaucrat::executeForm(Form &form) const
{
    if(!(form.getIsSigned()))
        std::cout << getName() << " can not execute because " << form.getName() << " is not signed." << std::endl;
    else
    {
        try
        {
            form.execute(*this);
            std::cout << _name << " executs " << form.getName() << "." << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cout << _name << " can not execute " << form.getName() << " because " << e.what() << std::endl;
        }
    }
}

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high: grade can't be higher than 1.");
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("grade too low: grade can't be lower than 150.");
}

std::ostream    &operator<<(std::ostream &os, Bureaucrat const &rhs)
{
    os << rhs.getName() << ", bureaucrate grade " << rhs.getGrade() << "." << std::endl;
    return (os);
}

