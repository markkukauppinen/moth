# MOTH

MOTH is a simple and light-weight header-only c++ unit testing framework.

This is an ideal unit testing framework for tiny projects where only basic
functionality of the application logic is to be verified.

## What's new?

|Date|Description|
|----|-----------|
| 2016-04-15 | First version with 6 basic CHECK routines (CHECK_EQUAL, CHECK_UNEQUAL, CHECK_NULL, CHECK_NON_NULL, CHECK_TRUE, CHECK_FALSE) |


## How to compile?

* MOTH unit testing framework is still in very early phase. So far is has has been succesfully compiled (Linux) with g++ and clang++ compilers
* To compile the source file you can use either g++ or clang++
    ```
    g++ -o moth moth.cpp
    clang++ -o moth moth.cpp
    ```
## How to embed it to my c++ project?
* Just create your own test suite file and include it in MOTH main source file. See examples in examples/ directory.

