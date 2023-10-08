
#ifndef CALCULATOR_PROCESSOR_H
#define CALCULATOR_PROCESSOR_H
#include "stack"
#include "string"

class Processor{
public:
    Processor();
    double process(std::stack<double> &numbers, std::stack<std::string> &operators);

};

#endif //CALCULATOR_PROCESSOR_H
