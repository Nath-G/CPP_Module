#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

// Colors
# define GREY		"[90m"
# define C_RES		"[0m"
# define YELLOW		"[33m"
# define BLUE		"[34m"
# define COLOR(id)	"[38;5;"#id"m"
# define CORAIL		COLOR(168)
# define GREEN_B	"[32;01m"

# include <iostream>
# include <string>
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
