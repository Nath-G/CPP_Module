#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include <iostream>
# include <string>
# include "color.hpp"
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
	private:
	//	int			_hp;
	//	std::string	_type;

	public:
		SuperMutant();
		SuperMutant(const SuperMutant & src);
		virtual ~SuperMutant();


		void		takeDamage(int);

		SuperMutant	&operator=(const SuperMutant & src);
};

#endif
