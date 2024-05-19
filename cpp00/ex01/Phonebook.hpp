#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
    private:
        Contact _contact[8];
        int     _num_cont;
        int     _tableDisplay();
        void    _details(int index);
        
    public:
        Phonebook();
        void    add();
        void    search();
        // void    exit();
};

#endif