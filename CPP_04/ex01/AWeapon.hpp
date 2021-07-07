#ifndef AWEAPON_HPP
# define AWEAPON_HPP

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

class AWeapon
{
	private:
		AWeapon();

    protected:
		std::string	_name;
		int			_apcost;
		int			_damage;

	public:
		AWeapon(std::string const &name, int apcost, int damage);
		AWeapon(const  AWeapon & src);
		virtual ~AWeapon();

		std::string	getName() const;
		void		setName(const std::string name);
		int			getAPCost() const;
		void		setAPCost(const int apcost);
		int			getDamage() const;
		void		setDamage(const int damage);

		virtual void		attack(void) const = 0;

		AWeapon	&operator=(const AWeapon & src);
};

std::ostream	&operator<<(std::ostream & os, const AWeapon & src);

#endif
