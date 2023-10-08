#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H
#include "ExpressionParser.h"
#include "Processor.h"
#include "LoaderLibrary.h"

class Calculator{
public:
    Calculator();
    void start();
private:
    ExpressionParser parser;
    Processor processor;
};

#endif //CALCULATOR_CALCULATOR_H
