#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
	private:
		Brain* _brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog& other);
		
		Dog &operator=(const Dog& other);

		void makeSound() const;
		void setIdea(size_t index, std::string idea);
		void getIdea(void) const;
};

#endif