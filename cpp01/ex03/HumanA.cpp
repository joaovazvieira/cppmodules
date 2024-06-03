#include "HumanA.hpp"

HumanA::HumanA(std::string	name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << "A new warrior " << _name << " arrives in town" << "\n";
}

HumanA::~HumanA()
{
	std::cout << _name << " dies in action" << std::endl;
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}