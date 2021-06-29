#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"
# include <iostream>
# include <string>
# include "color.hpp"

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
