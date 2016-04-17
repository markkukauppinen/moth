// MOTH is a header-only unit testing framework
// Copyright (c) 2016 Markku Kauppinen

#include "../../moth.h"
#include "myclass.h"

TEST_CASE(SuiteMyClass, Increment)
{
    MyClass obj;
    CHECK_EQUAL(0, obj._value);

    obj.increment();
    CHECK_EQUAL(1, obj._value);

    obj.increment();
    CHECK_EQUAL(2, obj._value);

    obj.increment();
    CHECK_EQUAL(3, obj._value);

    obj.increment();
    CHECK_EQUAL(4, obj._value);
}
