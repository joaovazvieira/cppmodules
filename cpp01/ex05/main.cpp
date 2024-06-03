#include "Harl.hpp"

int	main()
{
	Harl	chad = Harl();

	std::string	input[4] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
		chad.complain(input[i]);
	chad.complain("SLEEP");
	return 0;
}