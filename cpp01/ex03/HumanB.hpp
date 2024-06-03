#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string.h>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon*		_type;
	
	public:
		HumanB(std::string	name);
		~HumanB();
		Weapon const&	getWeapon();
		void	attack();
		void	setWeapon(Weapon& weapon);
};

#endif