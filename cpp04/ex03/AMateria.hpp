#ifndef AMAETERIA_HPP
#define AMAETERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;
class AMateria // A for abstract
{
	protected:
		std::string _type;

	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria();
		AMateria & operator=(AMateria const & src);

		std::string const & getType() const; // returns materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


#endif