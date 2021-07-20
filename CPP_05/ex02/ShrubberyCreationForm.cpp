/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:19:41 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/20 10:51:25 by nagresel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

static const char *SHRUBBERYFORM = ""
        "                                                         \n"
		"                      ,@@@@@@@,                          \n"
		"              ,,,.   ,@@@@@@/@@,  .oo8888o.              \n"
		"           ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o            \n"
		"          ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'         \n"
		"           %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'         \n"
		"          %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'           \n"
		"          `&%\\ ` /%&'   \\/./        \\ '|8'             \n"
		"            \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_   \n";

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("Shrubbery", 145, 137), target(target)
{
 //   this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src.getName(), 145, 137)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    this->Form::setIsSigned(rhs.getIsSigned());
//    this->_shrubbery = rhs._shrubbery;
    return (*this);
}



std::string     ShrubberyCreationForm::getShrubbery() const
{
    return (this->target);
}


void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!(this->getIsSigned()))
        throw FormUnsignedException();
    if (executor.getGrade() > this->getSignGradeRequired())
        throw GradeTooLowException();
    std::ofstream newFileStream;
    newFileStream.open((this->getShrubbery() + "_shrubbery").c_str());
    if (newFileStream.fail())
        throw OpeningFileException();
    newFileStream << SHRUBBERYFORM;
    newFileStream.close();
}

const char  *ShrubberyCreationForm::OpeningFileException::what() const throw()
{
    return ("Error at file opening.");
}
