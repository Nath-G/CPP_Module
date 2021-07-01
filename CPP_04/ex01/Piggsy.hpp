#ifndef PIGGSY_HPP
# define PIGGSY_HPP

# include <iostream>
# include <string>
# include "color.hpp"
# include "Enemy.hpp"

class Piggsy : virtual public Enemy
{
	private:

	public:
		Piggsy();
		Piggsy(const Piggsy & src);
		virtual ~Piggsy();

		Piggsy	&operator=(const Piggsy & src);
};

#endif
