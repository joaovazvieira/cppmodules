#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << "\n";
	_hitPoints = 100;
	_energyPoints = 50;
	_atkDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& name) : ClapTrap(name)
{
	std::cout << "ScavTrap copy constructor called" << "\n";
	*this = name;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << "\n";
}

ScavTrap & ScavTrap::operator=(const ScavTrap& scavtrap)
{
	std::cout << "ScavTrap assignation operator called" << "\n";
	_name = scavtrap._name;
	_hitPoints = scavtrap._hitPoints;
	_energyPoints = scavtrap._energyPoints;
	_atkDamage = scavtrap._atkDamage;
	_maxHitPoints = scavtrap._maxHitPoints;
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " has entered in safe Gate mode" << "\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
		return ;
	if (_energyPoints == 0)
	{
		std::cout << _name << " is out of energy" << "\n";
		return ;
	}
	_energyPoints -= 1;
	std::cout << _name << " attacks " << target << ", causing " << this->_atkDamage << " points of damage!" << "\n";
}
