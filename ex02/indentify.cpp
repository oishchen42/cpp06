#include "include.h"

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B *>(p))
        std::cout << "B\n";
    else
        std::cout << "C\n";
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A\n";
    }
    catch(const std::bad_cast& e)
    {
    }
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B\n";
    }
    catch(const std::bad_cast& e)
    {
    }
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C\n";
    }
    catch(const std::bad_cast& e)
    {
    }
}

Base* generate(void)
{
    int type = std::rand() % 3;
    if (type == 0)
        return (new A);
    else if (type == 1)
        return (new B);
    else
        return (new C);
}
