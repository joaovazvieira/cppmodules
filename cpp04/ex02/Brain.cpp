#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << "\n";
}

Brain::Brain(const Brain& src)
{
	std::cout << "Brain copy constructor called" << "\n";
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << "\n";
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << "Brain assignation operator called" << "\n";
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return (*this);
}

const std::string* Brain::getIdeaAddress(size_t index) const
{
	if (index < 100)
	{
		const std::string& idea = this->ideas[index];
		return (&idea);
	}
	std::cerr << "Index out of range" << std::endl;
	return (NULL);
}

const std::string Brain::getIdea(size_t index) const
{
	if (index < 100)
		return (this->ideas[index]);
	std::cerr << "Index out of range" << "\n";
	return (NULL);
}

void Brain::setIdea(size_t index, std::string idea)
{
	if (index < 100)
		this->ideas[index] = idea;
	else
		std::cerr << "Index out of range" << std::endl;
}