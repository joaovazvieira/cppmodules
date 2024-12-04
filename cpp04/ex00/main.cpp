#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const Animal* animal = new Animal();
std::cout << "\n";
	std::cout << dog->getType() << " " << "\n";
	std::cout << cat->getType() << " " << "\n";
	std::cout << animal->getType() << " " << "\n";
std::cout << "\n";
	dog->makeSound(); // expected output: Woof Woof
	cat->makeSound(); // expected output: Meow Meow
	animal->makeSound(); // expected output: Some sound
std::cout << "\n";
	delete dog;
	delete cat;
	delete animal;
std::cout << "\n";
	}
	// {

// 	Dog* newDog = new Dog();
// 	Dog* newDog2 = NULL;

// 	newDog2 = newDog;
// 	std::cout << newDog->getType();
// std::cout << "\n";
// 	newDog2->makeSound(); // expected output: Woof Woof
// 	std::cout << newDog << "\n" << newDog2 << "\n"; // expected output: same address
// std::cout << "\n";
// 	delete newDog;
// std::cout << "\n";
// 	}
// 	{
	
// 	Cat* newCat = new Cat();
// 	Cat* newCat2 = NULL;

// 	newCat2 = newCat;
// std::cout << "\n";
// 	newCat2->makeSound(); // expected output: Meow Meow
// 	std::cout << newCat << "\n" << newCat2 << "\n"; // expected output: same address
// std::cout << "\n";
// 	delete newCat;
// std::cout << "\n";
// 	}
// 	{

// 	const WrongAnimal* wrongcat = new WrongCat();
// 	const WrongAnimal* wronganimal = new WrongAnimal();
// std::cout << "\n";
// 	std::cout << wrongcat->getType() << " " << "\n";
// 	std::cout << wronganimal->getType() << " " << "\n";
// std::cout << "\n";
// 	wrongcat->makeSound();
// 	wronganimal->makeSound(); // expected output: WrongAnimal sound
// std::cout << "\n";
// 	delete wrongcat;
// 	delete wronganimal;
// 	}
// 	{
	
// 	WrongCat* newWrongCat = new WrongCat();
// 	WrongCat* newWrongCat2 = NULL;

// 	newWrongCat2 = newWrongCat;
// std::cout << "\n";
// 	newWrongCat2->makeSound(); // expected output: Wrong Meow Meow
// 	std::cout << newWrongCat << "\n" << newWrongCat2 << "\n"; // expected output: same address
// std::cout << "\n";
// 	delete newWrongCat;
// 	}
	return 0;
}