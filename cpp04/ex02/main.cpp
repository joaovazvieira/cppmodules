#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << dog->getType() << " " << "\n";
	std::cout << cat->getType() << " " << "\n";
	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;

// std::cout << "\n" << "---------------------" << "\n" << std::endl;

// 	Animal* arr[100];

// 	for (int i = 0; i < 100; i++)
// 	{
// 		if (i % 2 == 0)
// 			arr[i] = new Dog();
// 		else
// 			arr[i] = new Cat();
// 	}
// 	for (int i = 0; i < 100; i++)
// 		arr[i]->makeSound();
// 	for (int i = 0; i < 100; i++)
// 		delete arr[i];

// std::cout << "\n" << "---------------------" << "\n" << std::endl;

// 	Dog* doggy = new Dog();

// 	doggy->setIdea(0, "I am a dog");
// 	doggy->setIdea(1, "Fast as fuck doggo");

// 	Dog* doggly = new Dog(*doggy);

// 	doggly->setIdea(0, "Foooood");
// 	doggly->setIdea(1, "Gimme gimme that steak");

// 	std::cout << "Address doggy = " << doggy << "\n";
// 	doggy->getIdea();
// 	std::cout << "Address doggly = " << doggly << "\n";
// 	doggly->getIdea();

// 	delete doggy;
// 	delete doggly;

// std::cout << "\n" << "---------------------" << "\n" << std::endl;

// 	Cat* catty = new Cat();
// 	Cat* garfield = NULL;

// 	garfield = catty;
// 	std::cout << "address catty = " << catty << "\n";

// 	catty->setIdea(1, "purrr purrr");
// 	catty->getIdea();
// 	garfield->getIdea();

// 	std::cout << "Address of garfield = " << garfield << "\n";

// 	catty->setIdea(1, "where's my snack");
// 	catty->getIdea();
// 	garfield->getIdea();
// 	catty->setIdea(101, "Im getting angryyyy");

// 	delete catty;

	return 0;
}