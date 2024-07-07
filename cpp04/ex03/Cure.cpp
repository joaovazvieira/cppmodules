#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const & src) : AMateria(src) {}

Cure::~Cure() {}

Cure& Cure::operator=(Cure const & src)
{
	AMateria::operator=(src);
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << "\n";
}
