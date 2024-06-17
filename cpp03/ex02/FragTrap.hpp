#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& name);
		~FragTrap();

		FragTrap& operator=(const FragTrap& fragtrap);

		void	highFivesGuys(void);
		void	attack(const std::string& target);
};

#endif