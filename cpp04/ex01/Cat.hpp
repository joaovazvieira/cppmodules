#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
	private:
		Brain* _brain;

	public:
		Cat();
		virtual ~Cat();
		Cat(const Cat& other);
		
		Cat &operator=(const Cat& other);

		void makeSound() const;
		void setIdea(size_t index, std::string idea);
		void getIdea(void) const;
};

#endif