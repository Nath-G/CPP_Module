#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public virtual Form
{
    private:
        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

        void    execute(const Bureaucrat &executor);

    class OpeningFileException : public std::exception
    {
        public:
            const char  *what() const throw();
    }; 
};

#endif
