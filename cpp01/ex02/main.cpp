#include <string.h>
#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *PTR = &str;
	std::string &REF = str;

	std::cout << "Memory address of str " << &str << " and value of str " << str << std::endl;
	std::cout << "Memory address held by ptr " << PTR << " and value of ptr " << *PTR << std::endl; 
	std::cout << "Memory address held by ref " << &REF << " and value of ref " << REF << std::endl;
	return (0);
}