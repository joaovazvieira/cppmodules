#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctype.h>

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNum;
        std::string _secret;
        bool        emptySpace(std::string& str);

    public:
        void    init();
        bool    valid();	
        std::string     getFirst();
        std::string     getLast();
        std::string     getNick();
        std::string     getNumber();
        std::string     getSecret();
        
};

#endif