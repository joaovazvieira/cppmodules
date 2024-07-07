#ifndef ICAHRACTER_HPP
#define ICAHRACTER_HPP

#include "AMateria.hpp"
#include <string>

class AMateria;
class ICharacter // I for interface
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif