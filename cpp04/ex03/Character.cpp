#include "Character.hpp"

Character::Character(std::string const& name) : _name(name), _materiasCount(0)
{
	std::cout << "Charater constructor called" << "\n";
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

Character::Character(Character const& src) : _name(src._name), _materiasCount(src._materiasCount)
{
	std::cout << "Charater copy constructor called" << "\n";
	for (int i = 0; i < 4; i++)
	{
		if (src._materias[i])
			_materias[i] = src._materias[i]->clone(); // virtual function called from iCharacter
		else
			_materias[i] = NULL;
	}
}

Character::~Character()
{
	std::cout << "Charater destructor called" << "\n";
	for (int i = 0; i < 4; i++)
		if (_materias[i])
			delete _materias[i];
}

Character& Character::operator=(Character const& src)
{
	std::cout << "Charater assignation operator called" << "\n";
	if (this != &src)
	{
		_name = src._name;
		_materiasCount = src._materiasCount;
		for (int i = 0; i < 4; i++)
		{
			if (_materias[i])
				delete _materias[i];
			if (src._materias[i])
				_materias[i] = src._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	return *this;
}

std::string const & Character::getName() const { return _name; }

void Character::equip(AMateria* m)
{
	if (_materiasCount < 4 && m)
	{
		_materias[_materiasCount] = m;
		_materiasCount++;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < _materiasCount)
	{
		_materias[idx] = NULL;
		for (int i = idx; i < 3; i++)
		{
			_materias[i] = _materias[i + 1];
			_materias[i + 1] = NULL;
		}
		_materiasCount--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < _materiasCount && _materias[idx])
	{
		// ICharacter::use(idx, target);
		_materias[idx]->use(target);
	}
}
