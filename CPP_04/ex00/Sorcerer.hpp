#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"
# include "color.hpp"

class Sorcerer
{
	private:

		std::string	_name;
		std::string	_title;
		Sorcerer(); //can’t be instanciated without parameters 

	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const & src);
		virtual ~Sorcerer();

		Sorcerer		&operator=(Sorcerer const & src);

		std::string	getName(void) const;
		void		setName(const std::string name);
		std::string	getTitle(void) const;
		void		setTitle(const std::string title);
		void		polymorph(const Victim & target) const;
};

std::ostream	&operator<<(std::ostream & os, Sorcerer const & rsh);

#endif
