#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        std::string _name;
        int         _grade;
        void        checkGradeValue(int gradeValue);

    public:
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &src);
        virtual ~Bureaucrat();

        Bureaucrat  &operator=(Bureaucrat const &rhs);

        std::string getName()const;
        void        setName(const std::string name);
        int         getGrade()const;
        void        setGrade(int grade);
        void        incrementGrade();
        void        decrementGrade();
        void        signForm(Form &form) const;

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

};

    std::ostream    &operator<<(std::ostream &os, Bureaucrat const &rhs);


#endif
