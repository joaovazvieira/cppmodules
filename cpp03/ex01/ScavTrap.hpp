#ifndef	SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& name);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& scavtrap);

		void	guardGate();
		void	attack(const std::string& target);
};

#endif