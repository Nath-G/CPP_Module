#ifndef Donkey_HPP
# define Donkey_HPP

# include "Victim.hpp"
# include "Sorcerer.hpp"
# include <iostream>
# include <string>
# include "color.hpp"

class Donkey : virtual public Victim
{
	private:
		Donkey(); //can’t be instanciated without parameters 

	public:
		Donkey(std::string name);
		Donkey(Donkey const & src);
		virtual ~Donkey();

		Donkey		&operator=(Donkey const & src);
		void		getPolymorphed() const;
};

#endif
