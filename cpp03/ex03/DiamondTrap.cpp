#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << "\n";
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_atkDamage = FragTrap::_atkDamage;
	_maxHitPoints = FragTrap::_maxHitPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap& name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap copy constructor called" << "\n";
	*this = name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& name)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	_name = name._name;
	_hitPoints = name._hitPoints;
	_energyPoints = name._energyPoints;
	_atkDamage = name._atkDamage;
	_maxHitPoints = name._maxHitPoints;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << "\n";
}

void DiamondTrap::attack(const std::string& target) { ScavTrap::attack(target); }