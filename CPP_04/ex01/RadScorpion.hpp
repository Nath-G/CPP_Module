#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include <iostream>
# include <string>
# include "color.hpp"
# include "Enemy.hpp"

class RadScorpion : virtual public Enemy
{
	private:

	public:
		RadScorpion();
		RadScorpion(const RadScorpion & src);
		virtual ~RadScorpion();

		RadScorpion	&operator=(const RadScorpion & src);
};

#endif
