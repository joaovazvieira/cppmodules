#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _materias[4];
		int _materiasCount;

	public:
		Character(std::string const& name);
		Character(Character const& src);
		virtual ~Character();
		Character& operator=(Character const& src);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif