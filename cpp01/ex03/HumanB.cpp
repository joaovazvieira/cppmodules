#include "HumanB.hpp"

HumanB::HumanB(std::string	name) : _name(name), _type(NULL)
{
	std::cout << "A new warrior spawned as " << _name << "\n";
}

HumanB::~HumanB()
{
	std::cout << _name << " was killed in action" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_type = &weapon;
	std::cout << _name << " equiped their " << _type->getType() << "\n";
}

void	HumanB::attack()
{
	if (_type != NULL)
		std::cout << _name << " attacks with their " << _type->getType() << "\n";
	else
		std::cout << _name << " is unarmed" << "\n";
}
