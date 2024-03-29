#ifndef VICTIM_HPP
# define VICTIM_HPP

// Colors
# define GREY		"[90m"
# define C_RES		"[0m"

# include <iostream>
# include <string>


class Victim
{
	private:
		std::string	_name;
		Victim(); //can’t be instanciated without parameters 

	public:
		Victim(std::string name);
		Victim(Victim const & src);
		virtual ~Victim();


		std::string	getName(void) const;
		void		setName(const std::string name);

		Victim		&operator=(Victim const & src);
		virtual void		getPolymorphed() const;
};

std::ostream	&operator<<(std::ostream & os, Victim const & rsh);

#endif
