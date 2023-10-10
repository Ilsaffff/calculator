#pragma once
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


