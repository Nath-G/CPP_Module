#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include <iostream>
# include <string>
# include "color.hpp"
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
	private:
	//	int			_hp;
	//	std::string	_type;

	public:
		RadScorpion();
		RadScorpion(const RadScorpion & src);
		virtual ~RadScorpion();


		//void		takeDamage(int);

		RadScorpion	&operator=(const RadScorpion & src);
};

#endif
