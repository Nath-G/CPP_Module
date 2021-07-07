#ifndef PEON_HPP
# define PEON_HPP

// Colors
# define GREY		"[90m"
# define C_RES		"[0m"

# include "Victim.hpp"
# include <iostream>
# include <string>

class Peon : virtual public Victim
{
	private:
		Peon(void); //can’t be instanciated without parameters 

	public:
		Peon(std::string name);
		Peon(Peon const & src);
		virtual ~Peon(void);

		Peon		&operator=(Peon const & src);
		void		getPolymorphed() const;
};

#endif
