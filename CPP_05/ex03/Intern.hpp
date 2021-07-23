#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &src);
        virtual ~Intern();

        Intern  &operator=(const Intern &rhs);
        Form  *makeForm(const std::string &formName, const std::string &target)const;

    class FormUnknownException : public std::exception
        {
            public:
                const char  *what() const throw();
        };
};

#endif