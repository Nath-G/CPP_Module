#ifndef FLOWERTHROWER_HPP
# define FLOWERTHROWER_HPP

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

class Flowerthrower : virtual public AWeapon
{
	private:
		const std::string	_OutputOfAttack;

	public:
		Flowerthrower();
		Flowerthrower(const Flowerthrower & src);
		virtual ~Flowerthrower();

		void				attack() const;

		Flowerthrower			&operator=(const Flowerthrower & src);
};

#endif
