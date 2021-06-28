# include "Sorcerer.hpp"
//# include "Victim.hpp"
# include "Peon.hpp"
# include "Donkey.hpp"


int main(void)
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);
	Donkey martin("Martin");
	robert.polymorph(martin);

	return 0;
}

