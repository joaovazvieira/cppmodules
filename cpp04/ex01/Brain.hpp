#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		std::string ideas[100];

		Brain();
		Brain(const Brain& src);
		~Brain();

		Brain &operator=(const Brain& src);
		
		const std::string getIdea(size_t index) const;
		const std::string* getIdeaAddress(size_t index) const;
		void setIdea(size_t index, std::string idea);
};


#endif