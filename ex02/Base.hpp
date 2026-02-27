#pragma once

#include <iostream>
#include <cstdlib>

class Base
{
public:
    virtual ~Base() = default;
};

class A : public Base {};
class B : public Base {};
class C : public Base {};