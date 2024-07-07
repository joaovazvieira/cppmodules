#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	SlapTrap("Npc");
	ScavTrap	PunchTrap("Player");
	FragTrap	KickTrap("Boss");
	DiamondTrap	Diamond("God");

	std::cout << std::endl;

	SlapTrap.setAtkDamage(5);

	std::cout << "Npc" << " hp = " << SlapTrap.getHitPoints() << " atk = " << SlapTrap.getAtkDamage() << \
	" energy = " << SlapTrap.getEnergyPoints() << std::endl;
	std::cout << "Player" << " hp = " << PunchTrap.getHitPoints() << " atk = " << PunchTrap.getAtkDamage() << \
	" energy = " << PunchTrap.getEnergyPoints() << std::endl;
	std::cout << "Boss" << " hp = " << KickTrap.getHitPoints() << " atk = " << KickTrap.getAtkDamage() << \
	" energy = " << KickTrap.getEnergyPoints() << std::endl;
	std::cout << "God" << " hp = " << Diamond.getHitPoints() << " atk = " << Diamond.getAtkDamage() << \
	" energy = " << Diamond.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 100; i++)
	{
		if (SlapTrap.getHitPoints() <= 0 || PunchTrap.getHitPoints() <= 0)
			break ;
	std::cout << "\n";
	SlapTrap.attack("Player");
	PunchTrap.takeDamage(SlapTrap.getAtkDamage());
	KickTrap.attack("Player");
	PunchTrap.takeDamage(KickTrap.getAtkDamage());
	std::cout << "\n";
	if (SlapTrap.getHitPoints() <= 0 || PunchTrap.getHitPoints() <= 0)
			break ;
	PunchTrap.attack("Npc");
	PunchTrap.attack("Boss");
	SlapTrap.takeDamage(PunchTrap.getAtkDamage());
	KickTrap.takeDamage(PunchTrap.getAtkDamage());
	KickTrap.highFivesGuys();
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