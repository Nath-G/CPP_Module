#ifndef Donkey_HPP
# define Donkey_HPP

// Colors
# define GREY		"[90m"
# define C_RES		"[0m"


# include "Victim.hpp"
# include <iostream>
# include <string>

class Donkey : virtual public Victim
{
	private:
		Donkey(void); //can’t be instanciated without parameters 

	public:
		Donkey(std::string name);
		Donkey(Donkey const & src);
		virtual ~Donkey(void);

		Donkey		&operator=(Donkey const & src);
		void		getPolymorphed() const;
};

#endif
