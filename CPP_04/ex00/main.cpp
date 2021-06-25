# include "Sorcerer.hpp"


int main(void)
{
	Sorcerer a("Ro/b/ert", "the Magnificent");
	Sorcerer b(a);
	Sorcerer c("oups", "the Beautifull");
	c = b;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	Victim x("Jim", "the tanche");
	Victim y(x);
	Victim z("Joe", "the peureux");
	
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << z << std::endl;
	z.getPolymorphed();

	return 0;
}

