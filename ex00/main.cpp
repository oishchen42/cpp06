#include "ScalarConverter.hpp"
#include "include.h"

static void runTests(TestCase *tests, int count)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << "\n===Tests for: {" << tests[i].input << "; " << tests[i].type << "}===\n";
        ScalarConverter::convert(tests[i].input);
        std::cout << "======================\n";
    }
}

int main()
{
    int charCount = sizeof(charTests) / sizeof(charTests[0]);
    int intCount = sizeof(intTests) / sizeof(intTests[0]);
    int floatCount = sizeof(floatTests) / sizeof(floatTests[0]);
    int doubleCount = sizeof(doubleTests) / sizeof(doubleTests[0]);
    std::cout << "\n=== CHAR TESTS ===\n";
    runTests(charTests, charCount);
    std::cout << "\n=== INT TESTS ===\n";
    runTests(intTests, intCount);
    std::cout << "\n=== FLOAT TESTS ===\n";
    runTests(floatTests, floatCount);
    std::cout << "\n=== Double TESTS ===\n";
    runTests(doubleTests, doubleCount);
    return (0);
}