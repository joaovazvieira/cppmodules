#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << "\n";
}

Cat::Cat(const Cat& other) : Animal()
{
	*this = other;
	std::cout << "Cat copy constructor called" << "\n";
}

Cat::~Cat()
{
	if (this->_brain)
		delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignation operator called" << "\n";
	if (this != &other)
	{
		this->_type = other.getType();
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << "\n";
}

void Cat::setIdea(size_t index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

void Cat::getIdea(void) const
{
	for (int i= 0; i < 100; i++)
	{
		const std::string idea = this->_brain->getIdea(i);
		if (idea.length() == 0)
			continue;
		std::cout << "Idea " << i << ": " << idea << " at the address " << this->_brain->getIdeaAddress(i) << "\n";
	}
}