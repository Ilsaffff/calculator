
#ifndef CALCULATOR_PROCESSOR_H
#define CALCULATOR_PROCESSOR_H
#include "stack"
#include "string"
#include "LoaderLibrary.h"

class Processor{
public:
    Processor();
    double process(std::stack<double> &numbers, std::stack<std::string> &operators);
private:
    LoaderLibrary loaderLibrary;
};

#endif //CALCULATOR_PROCESSOR_H
