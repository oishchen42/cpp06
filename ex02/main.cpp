#include "include.h"

int main()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "\n===Test num: " << i << " ===\n";
        Base *base = generate();
        identify(base);
        identify(*base);
        delete base;
        std::cout << "=======================" << std::endl;
    }
    return 0;
}