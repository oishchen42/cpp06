#pragma once

#include <iostream>
#include <regex>

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
        void (*executer)(const std::string );
    };
    static const TypeDefiner types[];

    bool isChar(const std::string &str);
    bool isInt(const std::string &str);

    void convertChar(const std::string &str);
};