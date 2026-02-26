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