#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	SlapTrap("Npc");
	ScavTrap	PunchTrap("Player");

	std::cout << std::endl;

	SlapTrap.setAtkDamage(5);
	// PunchTrap.setAtkDamage(3);

	std::cout << "Npc" << " hp = " << SlapTrap.getHitPoints() << " atk = " << SlapTrap.getAtkDamage() << \
	" energy = " << SlapTrap.getEnergyPoints() << std::endl;
	std::cout << "Player" << " hp = " << PunchTrap.getHitPoints() << " atk = " << PunchTrap.getAtkDamage() << \
	" energy = " << PunchTrap.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 100; i++)
	{
		if (SlapTrap.getHitPoints() <= 0 || PunchTrap.getHitPoints() <= 0)
			break ;
	std::cout << "\n";
	SlapTrap.attack("Player");
	PunchTrap.takeDamage(SlapTrap.getAtkDamage());
	std::cout << "\n";
	if (SlapTrap.getHitPoints() <= 0 || PunchTrap.getHitPoints() <= 0)
			break ;
	PunchTrap.attack("Npc");
	SlapTrap.takeDamage(PunchTrap.getAtkDamage());
	std::cout << "\n";
	if (SlapTrap.getHitPoints() <= 0 || PunchTrap.getHitPoints() <= 0)
			break ;
	SlapTrap.beRepaired(3);
	PunchTrap.beRepaired(2);
	}
	PunchTrap.guardGate();
	std::cout << "\n";
	return 0;
}