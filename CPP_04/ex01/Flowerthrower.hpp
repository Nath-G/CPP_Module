#ifndef FLOWERTHROWER_HPP
# define FLOWERTHROWER_HPP

# include <iostream>
# include <string>
# include "color.hpp"
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
