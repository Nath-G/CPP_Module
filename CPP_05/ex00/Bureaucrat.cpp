#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    *this = src;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    this->_name = rhs.getName();
    this->_grade = rhs.getGrade();
    return (*this);
}

std::string     Bureaucrat::getName() const
{
    return(_name);
}

void        Bureaucrat::setName(std::string const name)
{
    this->_name = name;
}

int         Bureaucrat::getGrade() const
{
    return(this->_grade);
}

void        Bureaucrat::setGrade(int grade)
{
    this->_grade = grade;
}

void        Bureaucrat::incrementGrade()
{
}

void        Bureaucrat::decrementGrade()
{
}

std::ostream    &operator<<(std::ostream &os, Bureaucrat const &rhs)
{
    os << rhs.getName() << ", bureaucrate grade " << rhs.getGrade() << "." << std::endl;
    return (os);
}
/*
std::ostream &operator<<(std::ostream &os, const Victim & rsh)
{
	os << "I'm " << rsh.getName() << ", and I like others!" << std::endl;
	return (os);
}*/
