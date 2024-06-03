#include "Harl.hpp"

int	main(int argv, char **argc)
{
	if (argv != 2)
	{
		std::cout << "Not the right amount of arguments" << std::endl;
		return 1;
	}

	Harl	chad = Harl();
		chad.harlFilter(argc[1]);
	return 0;
}