#include "Contact.hpp"

static int	checkNum(std::string&	_phoneNum)
{
	while (1)
	{
    	std::cout << "Enter phone number  : " << "\n";
    	std::getline(std::cin, _phoneNum);
    	if (std::cin.eof())
        	return 1;
		int i = 0;
		for (i; _phoneNum[i]; i++)
			if (isdigit(_phoneNum[i]) == 0)
			{
				std::cout << "A phone number is requered" << "\n";
				break;
			}
		if (i == _phoneNum.size())
			return 0;
	}
	return 1;
}

void    Contact::init()
{
    std::cout << "Enter first name    : " << "\n";
    std::getline(std::cin, _firstName);
    if (std::cin.eof())
        return ;
    std::cout << "Enter last name     : " << "\n";
    std::getline(std::cin, _lastName);
    if (std::cin.eof())
        return ;
    std::cout << "Enter nickname      : " << "\n";
    std::getline(std::cin, _nickname);
    if (std::cin.eof())
        return ;
	if (checkNum(_phoneNum) == 1)
		return ;
    std::cout << "Enter Darkest secret: " << "\n";
    std::getline(std::cin, _secret);
    if (std::cin.eof())
        return ;
}

bool    Contact::emptySpace(std::string& str)
{
    return (str.find_first_not_of(" \t\n\r\f\v") == std::string::npos);
}

std::string Contact::getFirst()
{
    return(_firstName);
}

std::string Contact::getLast()
{
    return(_lastName);
}

std::string Contact::getNick()
{
    return(_nickname);
}

std::string Contact::getNumber()
{
    return(_phoneNum);
}

std::string Contact::getSecret()
{
    return(_secret);
}

bool    Contact::valid()
{
    if (emptySpace(_firstName))
        return false;
    if (emptySpace(_lastName))
        return false;
    if (emptySpace(_nickname))
        return false;
    if (emptySpace(_phoneNum))
        return false;
    if (emptySpace(_secret))
        return false;
    return true;
}
