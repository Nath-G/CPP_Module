# include "PlasmaRifle.hpp"

int main(void)
{
	PlasmaRifle a;
	PlasmaRifle b(a);
	PlasmaRifle c;
	c = b;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	return 0;
}

