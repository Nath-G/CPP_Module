/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:56:21 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/22 18:10:23 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Basic"),
                _signGradeRequired(20),
                _execGradeRequired(70),
                _isSigned(false)
{
}

Form::Form(std::string const &name, int const signGrade, int const execGrade, std::string const &target) :
                    _name(name),
                    _target(target),
                    _signGradeRequired(signGrade),
                    _execGradeRequired(execGrade),
                    _isSigned(false)
{
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();

}

Form::Form(Form const &src) : _name(src._name),
                            _signGradeRequired(src._signGradeRequired),
                            _execGradeRequired(src._execGradeRequired),
                            _isSigned(src._isSigned)
{
}

Form::~Form()
{
}

Form            &Form::operator=(const Form &rhs)
{
    _isSigned = rhs._isSigned;
    return (*this);
}

std::string     Form::getName() const
{
    return(this->_name);
}

std::string     Form::getTarget() const
{
    return(this->_target);
}

int         Form::getSignGradeRequired() const
{
    return(this->_signGradeRequired);
}

int         Form::getExecGradeRequired() const
{
    return(this->_execGradeRequired);
}

bool         Form::getIsSigned() const
{
    return(this->_isSigned);
}


void        Form::setIsSigned(bool b)
{
    this->_isSigned = b;
}

void        Form::beSigned(Bureaucrat someone)
{
        if (someone.getGrade() > this->_signGradeRequired)
        {
            throw Form::GradeTooLowException(); 
        }
       else
        {
            _isSigned = true;
        }
    return;
}

void    Form::execute(Bureaucrat const &executor)
{
    if (!(this->getIsSigned()))
        throw FormUnsignedException();
    if (executor.getGrade() > this->getExecGradeRequired())
        throw GradeTooLowException();
}

const char  *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high.");
}

const char  *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low.");
}

const char  *Form::FormUnsignedException::what() const throw()
{
    return ("Form unsigned.");
}

std::ostream     &operator<<(std::ostream &os, Form const &rhs)
{
    os << "Form " << rhs.getName() << " is " << (rhs.getIsSigned() ? "signed, " : "unsigned, ");
    os << "grade required to sign: " << rhs.getSignGradeRequired();
    os << ", grade required to execute: " << rhs.getExecGradeRequired() << std::endl;
 return (os);
}
