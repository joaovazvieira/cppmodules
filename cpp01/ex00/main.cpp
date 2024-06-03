#include "Zombie.hpp"

int	main(void)
{
	Zombie* zombie = newZombie("Rick");
	zombie->announce();
	delete zombie;
	randomChump("Charles");
	return 0;
}