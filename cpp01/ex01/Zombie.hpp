#ifndef	ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include <iostream>
#include <string>

class Zombie
{

	private:
		std::string	_name;

	public:
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
		void	setName(std::string name);
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif