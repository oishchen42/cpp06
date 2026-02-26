#include "ScalarConverter.hpp"
#include "include.h"

static void runTests(TestCase *tests, int count)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << "===Tests for: {" << tests[i].input << "; " << tests[i].type << "}\n";
        ScalarConverter::convert(tests[i].input);
        std::cout << "======================\n";
    }
}

int main()
{
    
}