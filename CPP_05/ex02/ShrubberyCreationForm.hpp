#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include <iostream>
# include <cstring>
# include <string>
# include "Form.hpp"
//# include "Bureaucrat.hpp"

//class Bureaucrat;

class ShrubberyCreationForm: public virtual Form
{
    private:
     //   const std::string target;
        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
        std::string     getShrubbery()const;

        void    execute(const Bureaucrat &executor) const;

    class OpeningFileException : public std::exception
    {
        public:
            const char  *what() const throw();
    }; 
};

#endif
