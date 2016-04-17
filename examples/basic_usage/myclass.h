// MOTH is a header-only unit testing framework
// Copyright (c) 2016 Markku Kauppinen

#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>

class MyClass
{
public:
    // Constructor
    MyClass();

    // Get string based on given id
    std::string getString(int id) const;

    // Verify that given id is valid
    bool isValidId(int id) const;
};

#endif // MY_CLASS_H
