#ifndef VICTIM_HPP
# define VICTIM_HPP

# include "Sorcerer.hpp"
# include <iostream>
# include <string>
# include "color.hpp"

class Victim
{
	private:

		Victim(); //can’t be instanciated without parameters 

	public:
		Victim(std::string name, std::string title);
		Victim(const Victim & src);
		virtual ~Victim();

		std::string	_name;
		std::string	_title;
		std::string	getName(void) const;
		void		setName(const std::string name);
		std::string	getTitle(void) const;
		void		setTitle(const std::string title);

		Victim		&operator=(const Victim & src);
		void		getPolymorphed() const;
};

std::ostream	&operator<<(std::ostream & os, const Victim & rsh);

#endif
