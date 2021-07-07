#ifndef CHARACTER_HPP
# define CHARACTER_HPP

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
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	private:
		std::string		_name;
		int				_ap; //action points
		AWeapon			*_weapon;
		Character();

	public:
		Character(const std::string &name);
		Character(const Character & src);
		~Character();
		Character	&operator=(const Character & src);

		std::string	getName(void) const;
		void		setName(const std::string name);
		int			getAP(void) const;
		void		setAP(const int AP);
		AWeapon		*getWeapon(void) const;
		//void		setWeapon(const AWeapon*);
		void		recoverAP();
		void		equip(AWeapon*);
		void		attack(Enemy*);

};

std::ostream	&operator<<(std::ostream & os, const Character & src);

#endif
