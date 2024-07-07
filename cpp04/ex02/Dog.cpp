#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << "\n";
}

Dog::Dog(const Dog& other) : AAnimal()
{
	*this = other;
	std::cout << "Dog copy constructor called" << "\n";
}

Dog::~Dog()
{
	if (this->_brain)
		delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignation operator called" << "\n";
	if (this != &other)
	{
		this->_type = other.getType();
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << "\n";
}

void Dog::setIdea(size_t index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

void Dog::getIdea(void) const
{
	for (int i= 0; i < 100; i++)
	{
		const std::string idea = this->_brain->getIdea(i);
		if (idea.length() == 0)
			continue;
		std::cout << "Idea " << i << ": " << idea << " at the address " << this->_brain->getIdeaAddress(i) << "\n";
	}
}