#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Ready to talk" << "\n";
}

Harl::~Harl()
{
	std::cout << "Bye have a nice day" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << "\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << "\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << "\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << "\n";
}

void	Harl::complain(std::string level)
{
	std::string		input[4] = {"debug", "info", "warning", "error"};
	void			(Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int				i = 0;;

	while (level != input[i] && i < 4)
		i++;
	if (i < 4)
		(this->*func[i])();
	else
		std::cout << "Chose a level plz" << level << "\n";
	return ;
}