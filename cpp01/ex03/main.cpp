#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main(void)
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		Weapon	dagger = Weapon("assasins dagger");
		HumanB	jim("jim");
		// jim.setWeapon(club);
		jim.attack();
		dagger.setType("bloody dagger");
		jim.setWeapon(dagger);
		jim.attack();
	}
	return 0;
}