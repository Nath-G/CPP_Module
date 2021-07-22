/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagresel <nagresel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:19:41 by nagresel          #+#    #+#             */
/*   Updated: 2021/07/22 17:31:29 by nagresel         ###   ########.fr       */
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

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("Shrubbery creation form", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src.getName(), 145, 137, src.getTarget())
{
    *this = src;
    this->Form::setIsSigned(0);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    this->Form::setIsSigned(rhs.getIsSigned());
    return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
    Form::execute(executor);
    std::ofstream newFileStream;
    newFileStream.open((this->getTarget() + "_shrubbery").c_str());
    if (newFileStream.fail())
        throw OpeningFileException();
    newFileStream << SHRUBBERYFORM;
    newFileStream.close();
}

const char  *ShrubberyCreationForm::OpeningFileException::what() const throw()
{
    return ("Error at file opening.");
}
