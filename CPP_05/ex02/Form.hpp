#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        Form();
        std::string const   _name;
        std::string const   _target;
        int const           _signGradeRequired;
        int const           _execGradeRequired;
        bool                _isSigned;

    public:
        Form(const std::string  &name, const int signGrade, const int execGrade, const std::string  &target);
        Form(const Form &src);
        virtual ~Form();
    
        Form            &operator=(const Form &rhs);

        std::string     getName(void)const;
        void            setName(const std::string name);
        std::string     getTarget(void)const;
        int             getSignGradeRequired(void)const;
        int             getExecGradeRequired(void)const;
        bool            getIsSigned()const;
        void            setIsSigned(bool);
        void            beSigned(Bureaucrat someone);
        virtual void    execute(Bureaucrat const &executor);

    class GradeTooHighException : public std::exception
    {
        public:
            const char  *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char  *what() const throw();
    };

    class FormUnsignedException : public std::exception
    {
        public:
            const char  *what() const throw();
    };
};

    std::ostream     &operator<<(std::ostream &os, const Form  &rhs);

#endif