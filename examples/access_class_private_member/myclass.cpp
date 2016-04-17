// MOTH is a header-only unit testing framework
// Copyright (c) 2016 Markku Kauppinen

#include "myclass.h"

MyClass::MyClass() :
    _value(0)
{
}

void MyClass::increment()
{
    ++_value;
}
