#include <iostream>

int main(int ac, char **av)
{
    (void)ac;
    (void)av;

    if (ac == 2)
    {
        std::string input = av[1];
        if (input.length() == 1)
        {
            char c = *(input.c_str());
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << std::endl;
        }
        std::cout << "double: " << static_cast<float>(std::stod(input));
    }
}