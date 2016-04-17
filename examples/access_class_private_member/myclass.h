// MOTH is a header-only unit testing framework
// Copyright (c) 2016 Markku Kauppinen

#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>

class SuiteMyClassIncrement;

class MyClass
{
public:
    // Constructor
    MyClass();

    // Increment _value by one
    void increment();

private:
    unsigned int _value;
    friend class SuiteMyClassIncrement;
};

#endif // MY_CLASS_H
