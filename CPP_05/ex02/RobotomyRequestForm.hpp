#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <fstream>
# include <iostream>
# include <cstring>
# include <string>
#include <cstdlib>

# include "Form.hpp"
//# include "Bureaucrat.hpp"

//class Bureaucrat;

class RobotomyRequestForm: public virtual Form
{
    private:
        RobotomyRequestForm();

    public:
        RobotomyRequestForm(const std::string & target);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
        std::string     getShrubbery()const;

        void    execute(const Bureaucrat &executor) const;

    class RobotomizedException : public std::exception
    {
        public:
            const char  *what() const throw();
    }; 
};

#endif
