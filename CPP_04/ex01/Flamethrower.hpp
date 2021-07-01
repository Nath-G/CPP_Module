#ifndef FLAMETHROWER_HPP
# define FLAMETHROWER_HPP

# include <iostream>
# include <string>
# include "color.hpp"
# include "AWeapon.hpp"

class Flamethrower : virtual public AWeapon
{
	private:
		const std::string	_OutputOfAttack;

	public:
		Flamethrower();
		Flamethrower(const Flamethrower & src);
		virtual ~Flamethrower();

		void				attack() const;

		Flamethrower			&operator=(const Flamethrower & src);
};

#endif
