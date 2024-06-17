#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "A new trap was spoted" << "\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _atkDamage(0), _maxHitPoints(_hitPoints)
{
	std::cout << "ClapTrap constructor called" << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& claptrap)
{
	std::cout << "copy constructor called" << "\n";
	*this = claptrap;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "assignation operator called" << "\n";
	_name = claptrap._name;
	_hitPoints = claptrap._hitPoints;
	_energyPoints = claptrap._energyPoints;
	_atkDamage = claptrap._atkDamage;
	_maxHitPoints = claptrap._maxHitPoints;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	if(_hitPoints == 0)
		return ;
	if (amount > _hitPoints)
	{
		_hitPoints = 0;
		std::cout << _name << " is dead" << "\n";
		return ;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << _name << " took " << amount << " damage" << "\n";
		std::cout << _name << " has " << _hitPoints << " left" << "\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
		return ;
	if (_hitPoints == _maxHitPoints)
	{
		std::cout << _name << " is already at max hp" << "\n";
		return ;
	}
	if (_hitPoints + amount > _maxHitPoints)
	{
		_hitPoints = _maxHitPoints;
		std::cout << _name << " is now at max hp" << "\n";
	}
	else
	{
		_hitPoints += amount;
		std::cout << _name << " has been repaired for " << amount << " hp" << "\n";
		std::cout << _name << " has " << _hitPoints << " hp" << "\n";
	}
}

int	ClapTrap::getHitPoints() const { return _hitPoints; }

int	ClapTrap::getEnergyPoints() const { return _energyPoints; }

int ClapTrap::getAtkDamage() const { return _atkDamage; }

int ClapTrap::setAtkDamage(int atkDamage) { return _atkDamage = atkDamage; }