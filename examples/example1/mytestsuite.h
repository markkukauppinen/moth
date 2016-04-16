// MOTH is a header-only unit testing framework
// Copyright (c) 2016 Markku Kauppinen

#include "../../moth.h"
#include "myclass.h"

TEST_CASE(SuiteMyClass, GetString)
{
    MyClass obj;
    CHECK_EQUAL("one", obj.getString(1));
    CHECK_EQUAL("two", obj.getString(2));
    CHECK_EQUAL("three", obj.getString(3));
    CHECK_EQUAL("four",  obj.getString(4));
}

TEST_CASE(SuiteMyClass, IsValidId)
{
    MyClass obj;
    CHECK_FALSE(obj.isValidId(0));
    CHECK_TRUE(obj.isValidId(1));
    CHECK_TRUE(obj.isValidId(2));
    CHECK_TRUE(obj.isValidId(3));
    CHECK_TRUE(obj.isValidId(4));
    CHECK_FALSE(obj.isValidId(5));
}
