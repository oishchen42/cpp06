#pragma once

#include <iostream>
#include <regex>
#include <limits>
#include <cmath>

#define FUNCTION_CHEKERS 4

class ScalarConverter
{
public:
    ScalarConverter() = delete;
    ~ScalarConverter() = delete;
    ScalarConverter(const ScalarConverter &other) = delete;
    ScalarConverter& operator=(const ScalarConverter &other) = delete;

    static void convert(const std::string &str);

private:
    struct TypeDefiner
    {
        bool (*validator)(const std::string &str);
        void (*executor)(const std::string &str);
    };
    static const TypeDefiner types[];

    static bool isChar(const std::string &str);
    static bool isInt(const std::string &str);
    static bool isFloat(const std::string &str);
    static bool isDouble(const std::string &str);

    static void convertChar(const std::string &str);
    static void convertInt(const std::string &str);
    static void convertFloat(const std::string &str);
};