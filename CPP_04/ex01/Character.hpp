#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "color.hpp"
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
