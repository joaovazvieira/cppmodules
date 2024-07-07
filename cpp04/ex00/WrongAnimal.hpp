#ifndef WRONGANIAML_HPP
#define WRONGANIAML_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal &operator=(const WrongAnimal& other);

		void makeSound() const;
		std::string getType() const;
};

#endif