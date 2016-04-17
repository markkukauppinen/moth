# MOTH

MOTH is a super simple and light-weight header-only c++ unit testing framework.

## License

Please see https://github.com/markkukauppinen/moth/blob/master/LICENSE for general license information.

## What's new?

|Date|Description|
|----|-----------|
| 2016-04-17 | Added and updated examples. Updated documentation |
| 2016-04-16 | Added CHECK_THROW and CHECK_NOT_THROW |
| 2016-04-15 | First version with 6 basic CHECK routines (CHECK_EQUAL, CHECK_UNEQUAL, CHECK_NULL, CHECK_NON_NULL, CHECK_TRUE, CHECK_FALSE) |


## How to compile?

* MOTH unit testing framework is still in very early phase. So far is has has been succesfully compiled (Linux) with g++ and clang++ compilers
* To compile the source file you can use either g++ or clang++

    ```
    g++ -o moth moth.cpp
    clang++ -o moth moth.cpp
    ```

## How to use MOTH?

* To get started, all you have to do is to write your own test suite file in separate header file, include it in the MOTH main source file, and compile. See examples folder for some examples on how to use MOTH.

### Basic usage

You might already have a class which you would like to test, for example a class called MyClass. Let's name the header file to myclass.h

```
class MyClass
{
public:
    // Constructor
    MyClass()
    {}

    // Get string based on given id
    std::string getString(int id) const
    {
        std::string ret;
        switch(id)
        {
            case 1: ret.assign("one");
                break;
            case 2: ret.assign("two");
                break;
            default:
                break;
        }
        return ret;
    }
    
    // Verify that given id is valid
    bool isValidId(int id) const
    {
        return (id == 1 || id == 2);
    }
};
```

If you wanted to test the output of the member functions getString and isValid(), you would start writing a test suite for those by creating a new header file, for example mytestsuite.h. In the file you should include the moth.h header file, and the header file of the class which functionality you would like to test. In this case mytest.h.

TEST_CASE and all CHECK macros are defined in moth.h header file. TEST_CASE obviously creates a new test case and the content of the case are written inside curly brackets. CHECK macros take in arguments and verifies the functinality of the class under testing against those arguments.

```
#include "moth.h"
#include "myclass.h"

TEST_CASE(SuiteMyClass, GetString)
{
    MyClass obj;
    CHECK_EQUAL("", obj.getString(0));
    CHECK_EQUAL("one", obj.getString(1));
    CHECK_EQUAL("two", obj.getString(2));
    CHECK_EQUAL("",  obj.getString(3));
}

TEST_CASE(SuiteMyClass, IsValidId)
{
    MyClass obj;
    CHECK_FALSE(obj.isValidId(0));
    CHECK_TRUE(obj.isValidId(1));
    CHECK_TRUE(obj.isValidId(2));
    CHECK_FALSE(obj.isValidId(3));
}
```

And finally, last thing to do is to include your test suite header file in the MOTH main source file

```
#include "moth.h"
#include "mytestsuite.h"

int main(int argc, char** argv)
{
    TestRunner::run();
    return 0;
}
```

### Accessing private member variables of a class

Let's start by creating a class with at least one private member variable and a modifier function for it. Let's name the header file to myclass.h.

```
class MyClass
{
public:
    // Constructor
    MyClass() :
        _value(0)
    {}

    // Increment _value by one
    void increment()
    {
        ++_value;
    }

private:
    unsigned int _value;
}
```

If you wanted to verify the value of the member variable _value, you should write a test suite for it by creating a new header file, for example mytestsuite.h. In the file you should include the moth.h header file, and the header file of the class which functionality you would like to test. In this case mytest.h.

TEST_CASE and all CHECK macros are defined in moth.h header file. TEST_CASE obviously creates a new test case and the content of the case are written inside curly brackets. CHECK macros take in arguments and verifies the functionality of the class under testing against those arguments.

```
#include "moth.h"
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
```

If you would try to compile the unit tests now, you would get a compiler error stating that _value is a private member of MyClass and cannot be accessed by the test suite. The solution to get an access to the private member is to add a forward declaration and a friend class definition in the class which is under testing. As you can see, the class name to be used in the forward declaration and in the friend class definition is a concatenation of your test suite + test case (SuiteMyClass + Increment).

```
class SuiteMyClassIncrement;

class MyClass
{
public:
    // Constructor
    MyClass() :
        _value(0)
    {}

    // Increment _value by one
    void increment()
    {
        ++_value;
    }

private:
    unsigned int _value;
    friend class SuiteMyClassIncrement;
};
```

And finally, last thing to do is to include your test suite header file in the MOTH main source file

```
#include "moth.h"
#include "mytestsuite.h"

int main(int argc, char** argv)
{
    TestRunner::run();
    return 0;
}
```
