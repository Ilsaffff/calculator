#pragma once
#include <string>
#include <set>
#include "ExpressionParser.h"
#include "Processor.h"

class ExpressionParser {
public:
    double parse(std::string& expression, Processor& processor);
private:
    std::set<std::string> validFunctions = {"sin", "cos", "tg", "ctg", "ln"};
    std::set<std::string> validSimpleFunctions = {"+", "-", "*", "/", "^"};
    void readNumber(std::string &expression, std::stack<double> &numbers, size_t &i);
    void readFunction(std::string &expression, std::stack<std::string> & operators, size_t &i);
    int getPriority(std::string &operator2);
};
#pragma once
