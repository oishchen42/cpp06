#pragma once

#include <iostream>

struct TestCase {
    std::string input;
    std::string type;
};

TestCase charTests[] = {
    { "c", "char" },
    { "a", "char" },
    { "*", "char" },
    { "0", "int (special case char/int check)"},
    { "\t", "non-printable"}
};

TestCase intTests[] = {
    { "18", "int" },
    { "-19", "int" },
    { "+02", "char" },
    { "21474836477", "overlapp"},
    { "-21474836477", "overlapp"},
    {"+99999999999999999999999999999999", "very big number"}
};

TestCase floatTests[] = {
    { "-99999999999999999999999900000000099999999.99999999999999999999999999999999f", "very big number" },
    { "4.2f", "float" },
    { ".42f", "float" },
    { "42.f", "float" },
    { "0.0f", "float zero" }, 
    { "-inff", "negative infinity" },
    { "+inff", "positive infinity" },
    { "nanf", "not a number" },
    { "inff", "infinity (implicit positive)" }
};

TestCase doubleTests[] = {
    { "-inf", "negative infinity" },
    { "+inf", "positive infinity" },
    { "nan", "not a number" },
    { "inf", "infinity (implicit positive)" }
};