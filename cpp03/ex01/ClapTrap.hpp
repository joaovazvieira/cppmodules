#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _atkDamage;
		unsigned int _maxHitPoints;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& name);
		ClapTrap& operator=(const ClapTrap& name);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int	getHitPoints() const;
		int	getEnergyPoints() const;
		int	getAtkDamage() const;
		int	setAtkDamage(int atkDamage);
};

#endif