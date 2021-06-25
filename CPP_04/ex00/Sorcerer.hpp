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
		Sorcerer(const Sorcerer & src);
		virtual ~Sorcerer();

		Sorcerer		&operator=(const Sorcerer & src);

		std::string	getName(void) const;
		void		setName(const std::string name);
		std::string	getTitle(void) const;
		void		setTitle(const std::string title);
	//	void		polymorph(Victim const &target)const;

};

std::ostream	&operator<<(std::ostream & os, const Sorcerer & rsh);

#endif
