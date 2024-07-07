#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_atkDamage = 30;
	std::cout << "FragTrap constructor called" << "\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << "\n";
	_hitPoints = 100;
	// _energyPoints = 100;
	_atkDamage = 30;
}

FragTrap::FragTrap(const FragTrap& name) : ClapTrap(name)
{
	std::cout << "FragTrap copy constructor called" << "\n";
	*this = name;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << "\n";
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap)
{
	std::cout << "FragTrap assignation operator called" << "\n";
	_name = fragtrap._name;
	_hitPoints = fragtrap._hitPoints;
	_energyPoints = fragtrap._energyPoints;
	_atkDamage = fragtrap._atkDamage;
	_maxHitPoints = fragtrap._maxHitPoints;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " is asking for a high five" << "\n";
}

void	FragTrap::attack(const std::string& target)
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
