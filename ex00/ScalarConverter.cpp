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
    {ScalarConverter::isInt, &ScalarConverter::convertInt},
    {ScalarConverter::isFloat, &ScalarConverter::convertFloat},
    {ScalarConverter::isDouble, &ScalarConverter::convertFloat},
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
                return;
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

bool ScalarConverter::isInt(const std::string &str)
{
    std::regex regex("^[+-]?[0-9]+$");
    if(!std::regex_match(str, regex))
        return (false);
    return (true);
}

bool ScalarConverter::isFloat(const std::string &str)
{
    std::regex regex("^[+-]?([0-9]*\\.[0-9]+|[0-9]+\\.[0-9]*)[fF]$|^([+-]?inff|nanf)$");
    if(!std::regex_match(str, regex))
        return (false);
    return (true);
}

bool ScalarConverter::isDouble(const std::string &str)
{
    std::regex regex("^[+-]?([0-9]*\\.[0-9]+|[0-9]+\\.[0-9]*)$|^([+-]?inf|nan)$");
    if(!std::regex_match(str, regex))
        return (false);
    return (true);
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
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string &str)
{
    try 
    {
        double number = std::stod(str);
        if (str.length() == 1)
            std::cout << "char: " << str[0] << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (static_cast<float>(std::numeric_limits<int>::max()) - number > 0.001
        || static_cast<float>(std::numeric_limits<int>::min()) - (-number) < -0.001)
            std::cout << "int: " << static_cast<int>(number) << std::endl;
        else
            std::cout << "int: impossible\n";
        std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
        std::cout << "double: " << number << ".0" << std::endl;
    }
    catch(std::exception &e)
    {
        // std::cout << e.what() << std::endl;
        printBaseCase();
    }
}

void ScalarConverter::convertFloat(const std::string &str)
{
    // double d = std::numeric_limits<double>::max();
    // std::cout << "max:d: " << d << std::endl;
    try 
    {
        double number = std::stod(str);
        if (str.length() > 10)
            std::cout << "our double: " << number << std::endl;
        std::cout << "char: impossible\n";
        if (std::isnan(number) || std::isinf(number)
        || number > static_cast<float>(std::numeric_limits<int>::max())
        || number < static_cast<float>(std::numeric_limits<int> ::min()))
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(number) << std::endl;
        std::cout << "float: " << number;
        if (!std::isnan(number) && !std::isinf(number) && number == static_cast<long>(number))
        {
            std::cout << ".0f\n";
            std::cout << "double: " << number << ".0\n";
        }
        else
        {
            std::cout << "f\n";
            std::cout << "double: " << number << "\n";
        }
    }
    catch(std::exception &e)
    {
        // std::cout << e.what() << std::endl;
        printBaseCase();
    }
}
