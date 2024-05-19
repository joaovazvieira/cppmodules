#include "Phonebook.hpp"

Phonebook::Phonebook() : _num_cont(0) {}

static  std::string str_cut(const std::string& str)
{
    std::string    newName(str);

    if (str.length() <= 10)
        return str;
    newName.erase(10, newName.npos);
    newName[9] = '.';
    return (newName);
}

int Phonebook::_tableDisplay()
{
    if (_num_cont == 0)
    {
        std::cout << "No contacts to display" << std::endl;
        return 0;
    }
    std::cout << "--------------------------------------------------" << "\n";
    for (int    i = 0; i < _num_cont; i++)
    {
        std::cout << "|" << std::setw(10) << std::right << i;
        std::cout << "|" << std::setw(10) << std::right << str_cut(_contact[i].getFirst());
        std::cout << "|" << std::setw(10) << std::right << str_cut(_contact[i].getLast());
        std::cout << "|" << std::setw(10) << std::right << str_cut(_contact[i].getNumber());
        std::cout << "|" << std::endl;
    }
    std::cout << "--------------------------------------------------" << "\n";
    return 1;
}

void    Phonebook::_details(int index)
{
    std::cout << "First Name    : " << _contact[index].getFirst() << "\n";
    std::cout << "Last Name     : " << _contact[index].getLast() << "\n";
    std::cout << "Nickname      : " << _contact[index].getNick() << "\n";
    std::cout << "Phone Number  : " << _contact[index].getNumber() << "\n";
    std::cout << "Darkest Secret: " << _contact[index].getSecret() << std::endl;
}

void    Phonebook::add()
{
    Contact new_contact;
    static  int i = 0;

    new_contact.init();
    if (!new_contact.valid())
    {
        std::cout << "Error" << std::endl;
        return ;
    }
    _num_cont = i < 8 ? i + 1 : 8; //fancy
    _contact[i % 8] = new_contact;
    i++;
}

void    Phonebook::search()
{
    int         index = -1;
    std::string inp_index;

    if (!_tableDisplay())
        return ;
    std::cout << std::endl;
    while (index < 0 || index >= _num_cont)
    {
        std::cout << "Enter valid index" << "\n";
        std::getline(std::cin, inp_index);
        if (std::cin.eof())
            return ;
        try{
            index = std::stoi(inp_index);
        }
        catch (const std::invalid_argument& e)
        {
            std::cerr << "Error index:" << e.what() << std::endl;
            return ;
        }
        catch (const std::out_of_range& e)
        {
            std::cerr << "Index out of range: " << e.what() << std::endl;
            return ;
        }
    }
    _details(index);
}