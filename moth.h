// MOTH is a header-only unit testing framework
// Copyright (c) 2016 Markku Kauppinen

#ifndef MOTH_H
#define MOTH_H

#include <iostream>
#include <vector>

class TestRunner;

#define CHECK_EQUAL(a,b)\
if(a != b)\
    TestRunner::failed(__FILE__, __LINE__);\

#define CHECK_UNEQUAL(a,b)\
if(a == b)\
    TestRunner::failed(__FILE__, __LINE__);\

#define CHECK_NULL(a)\
if(a != 0)\
    TestRunner::failed(__FILE__, __LINE__);\

#define CHECK_NON_NULL(a)\
if(a == 0)\
    TestRunner::failed(__FILE__, __LINE__);\

#define CHECK_TRUE(a)\
if(a != true)\
    TestRunner::failed(__FILE__, __LINE__);\

#define CHECK_FALSE(a)\
if(a != false)\
    TestRunner::failed(__FILE__, __LINE__);\

#define CHECK_THROW(a,b)\
try { a; }\
catch(const b&) {}\
catch(...) { TestRunner::failed(__FILE__, __LINE__); }\

#define CHECK_NOT_THROW(a,b)\
try { a; }\
catch(const b&) { TestRunner::failed(__FILE__, __LINE__); }\
catch(...) {}\

class Base
{
public:
    virtual void run() = 0;
    virtual std::string getId() const = 0;
};

#define TEST_CASE(suite, test)\
class suite##test : public Base\
{\
public:\
    suite##test()\
    { TestRunner::add(this); }\
    virtual void run();\
    virtual std::string getId() const\
    {\
        std::string id = #suite;\
        id += "::";\
        id += #test;\
        return id;\
    }\
};\
suite##test obj##suite##test;\
void suite##test::run()

class TestRunner
{
public:
    static void run()
    {
        std::vector<Base*>::const_iterator it = _cases.begin();
        while(it != _cases.end())
        {
            std::cout << "Running " << (*it)->getId() << std::endl;
            (*it)->run();
            ++it;
        }

        result();
    }

    static void failed(const char* file, int line)
    {
        std::cout << "\tError in " << file << ", line " << line << std::endl;
        ++_failures;
    }

    static void add(Base* base)
    {
        _cases.push_back(base);
    }

private:
    static void result()
    {
        if(_cases.empty())
            std::cout << "No test cases found!" << std::endl;
        else if(_failures == 0)
            std::cout << "All test cases passed!" << std::endl;
        else
            std::cout << _failures << " test cases failed!" << std::endl;
    }

    static unsigned int _failures;
    static std::vector<Base*> _cases;
};

unsigned int TestRunner::_failures = 0;
std::vector<Base*> TestRunner::_cases;
#endif // MOTH_H
