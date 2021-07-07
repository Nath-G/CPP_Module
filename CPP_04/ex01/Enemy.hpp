#ifndef ENEMY_HPP
# define ENEMY_HPP

// Colors
# define GREY		"[90m"
# define C_RES		"[0m"
# define YELLOW		"[33m"
# define BLUE		"[34m"
# define COLOR(id)	"[38;5;"#id"m"
# define CORAIL		COLOR(168)
# define ORANGE		COLOR(130)
# define SKY_BLUE	COLOR(69)
# define GREEN_B	"[32;01m"
# define RED 		"[31m"

# include <iostream>
# include <string>

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
