#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include <string>
# include "color.hpp"

class Enemy
{
	protected:
		int			_hp;
		std::string	_type;
		Enemy();

	public:
		Enemy(int, std::string);
		Enemy(const Enemy & src);
		virtual ~Enemy();

		int				getHP(void) const;
		void			setHP(const int hp);
		std::string		getType(void) const;
		void			setType(const std::string type);

		virtual void	takeDamage(int);

		Enemy		&operator=(const Enemy & src);
};

std::ostream	&operator<<(std::ostream & os, const Enemy & src);

#endif
