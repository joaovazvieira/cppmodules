#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            for (int j = 0; argv[i][j]; j++)
            {
                if (islower(argv[i][j]))
                    argv[i][j] = (char)toupper((int)argv[i][j]);
            }
            std::cout << argv[1];
        }
        std::cout << std::endl;
    }
    return 0;
}