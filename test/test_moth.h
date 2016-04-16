// MOTH is a header-only unit testing framework
// Copyright (c) 2016 Markku Kauppinen

#include "../moth.h"
#include <stdexcept>

TEST_CASE(MOTH, CheckEqual)
{
    CHECK_EQUAL(1,1);
    CHECK_EQUAL("String", "String");
    CHECK_EQUAL(2.00, 2.00);
    CHECK_EQUAL(true, true);
}

TEST_CASE(MOTH, CheckUnequal)
{
    CHECK_UNEQUAL(1,2);
    CHECK_UNEQUAL("String", "Strign");
    CHECK_UNEQUAL(2.00, 2.01);
    CHECK_UNEQUAL(true, false);
}

TEST_CASE(MOTH, CheckNull)
{
    char* data = 0;
    CHECK_NULL(data);
}

TEST_CASE(MOTH, CheckNonNull)
{
    char data[2];
    CHECK_NON_NULL(&data);
}

TEST_CASE(MOTH, CheckTrue)
{
    bool flag = true;
    CHECK_TRUE(flag);
}

TEST_CASE(MOTH, CheckFalse)
{
    bool flag = false;
    CHECK_FALSE(flag);
}

TEST_CASE(MOTH, CheckThrow)
{
    struct Moth
    {
        void execThrow()
        {
            const std::runtime_error error("moth_err");
            throw error;
        }
    };

    Moth obj;
    CHECK_THROW(obj.execThrow(), std::runtime_error);
}

TEST_CASE(MOTH, CheckNotThrow)
{
    struct Moth
    {
        void execThrow()
        {
            const std::runtime_error error("moth_err");
            throw error;
        }
    };

    Moth obj;
    CHECK_NOT_THROW(obj.execThrow(), std::logic_error);
}
