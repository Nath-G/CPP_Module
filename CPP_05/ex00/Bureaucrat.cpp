/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:57:06 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/19 13:57:08 by nagresel         ###   ########.fr       */
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
    *this = src;
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
    --_grade;
}

void        Bureaucrat::decrementGrade()
{
    checkGradeValue(_grade + 1);
    ++_grade;
}


void        Bureaucrat::checkGradeValue(int gradeValue)
{
    if (gradeValue < 1)
        throw Bureaucrat::GradeTooHighException();
    if (gradeValue > 150)
        throw Bureaucrat::GradeTooLowException();
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

