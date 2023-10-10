#ifndef CALCULATOR_SHAREDLIBRARY_H
#define CALCULATOR_SHAREDLIBRARY_H

#include "dlfcn.h"
#include "iostream"
#include <string>
#include <sstream>

class SharedLibrary {
public:
    void loadLibrary(const std::string &nameLibrary);

    double runFunc(std::string name, const double &value);

    double runFunc(std::string name, const double &value1, const double &value2);

    std::string name;

//    ~SharedLibrary();

private:
    void *handler;

};

#endif //CALCULATOR_SHAREDLIBRARY_H
