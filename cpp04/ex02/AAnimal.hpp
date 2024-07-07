#ifndef AANIMAL_HPP
#define	AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	protected:
		std::string _type;
	
	public:
		AAnimal();
		AAnimal(std::string);
		virtual ~AAnimal(); // virtual destructor
		AAnimal(const AAnimal& other);

		AAnimal &operator=(const AAnimal& other);

		virtual void makeSound() const = 0; // pure virtual function
		std::string getType() const;
};

#endif