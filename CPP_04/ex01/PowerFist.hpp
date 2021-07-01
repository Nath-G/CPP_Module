#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include <iostream>
# include <string>
# include "color.hpp"
# include "AWeapon.hpp"

class PowerFist : virtual public AWeapon
{
	private:
		const std::string	_OutputOfAttack;

	public:
		PowerFist();
		PowerFist(const PowerFist & src);
		virtual ~PowerFist();

		void				attack() const;

		PowerFist			&operator=(const PowerFist & src);
};

#endif
