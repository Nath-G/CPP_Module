#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "Form.hpp"

class RobotomyRequestForm: public virtual Form
{
    private:
        RobotomyRequestForm();

    public:
        RobotomyRequestForm(const std::string & target);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

        void    execute(const Bureaucrat &executor);
};

#endif
