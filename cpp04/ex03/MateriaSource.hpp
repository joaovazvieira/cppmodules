#ifndef MATTERIASOURCE_HPP
#define MATTERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _materias[4];
		int _materiasCount;

	public:
		MateriaSource();
		MateriaSource(MateriaSource const& src);
		virtual ~MateriaSource();
		MateriaSource& operator=(MateriaSource const& src);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif