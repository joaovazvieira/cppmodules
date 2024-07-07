#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materiasCount(0)
{
	std::cout << "MateriaSource constructor called" << "\n";
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& src) : _materiasCount(src._materiasCount)
{
	std::cout << "MateriaSource copy constructor called" << "\n";
	for (int i = 0; i < 4; i++)
	{
		if (src._materias[i])
			_materias[i] = src._materias[i]->clone();
		else
			_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << "\n";
	for (int i = 0; i < 4; i++)
		if (_materias[i])
			delete _materias[i];
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src)
{
	std::cout << "MateriaSource assignation operator called" << "\n";
	if (this != &src)
	{
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

void MateriaSource::learnMateria(AMateria* m)
{
	if (_materiasCount < 4 && m)
	{
		_materias[_materiasCount] = m;
		_materiasCount++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_materias[i] && _materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	return NULL;
}

