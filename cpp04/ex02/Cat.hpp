#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public AAnimal
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