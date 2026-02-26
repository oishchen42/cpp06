#include "ScalarConverter.hpp"

static void printBaseCase(void)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

const ScalarConverter::TypeDefiner ScalarConverter::types[] =
{
    {ScalarConverter::isChar, &ScalarConverter::convertChar},
};


void ScalarConverter::convert(const std::string &str)
{
    if (!str.empty())
    {
        for (int i = 0; i < FUNCTION_CHEKERS; i++)
        {
            if (types[i].validator(str))
            {
                types[i].executor(str);

            }
        }
    }
    printBaseCase();
}

// Functions validators:
bool ScalarConverter::isChar(const std::string &str)
{
    return (str.length() == 1 && !std::isdigit(str[0]));
}

void ScalarConverter::convertChar(const std::string &str)
{
    char c = str[0];
    if (std::isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: non-displayable\n";
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << static_cast<double>(c) << std::endl;
}