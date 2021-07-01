#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include <iostream>
# include <string>
# include "color.hpp"
# include "AWeapon.hpp"

class PlasmaRifle : virtual public AWeapon
{
	private:
		const std::string	_OutputOfAttack;

	public:
		PlasmaRifle();
		PlasmaRifle(const PlasmaRifle & src);
		virtual ~PlasmaRifle();

		void				attack() const;

		PlasmaRifle			&operator=(const PlasmaRifle & src);
};

#endif
