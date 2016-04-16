// MOTH is a header-only unit testing framework
// Copyright (c) 2016 Markku Kauppinen

#include "myclass.h"

MyClass::MyClass()
{
}

std::string MyClass::getString(int id) const
{
    std::string ret;
    switch(id)
    {
        case 1: ret.assign("one");
            break;
        case 2: ret.assign("two");
            break;
        case 3: ret.assign("three");
            break;
        case 4: ret.assign("four");
            break;
        default:
            break;
    }
    return ret;
}

bool MyClass::isValidId(int id) const
{
    return (id > 0 && id < 5);
}
