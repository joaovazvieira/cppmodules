#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& name);
		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& diamondtrap);

		void	whoAmI();
		void	attack(const std::string& target);
};

#endif