#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "A new Zombie is born as " << _name << "\n";
}

Zombie::~Zombie()
{
	std::cout << _name << " had is head crushed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << "\n";
}