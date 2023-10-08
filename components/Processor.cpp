#include <iostream>
#include <map>
#include "Processor.h"


Processor::Processor() = default;


// method which calculate expression
double Processor::process(std::stack<double> &numbers, std::stack<std::string> &operators) {
    double result;
    double num1;
    double num2;

    num1 = numbers.top();
    numbers.pop();
    std::string operator_ = operators.top();
    operators.pop();
    if (operator_ == "sin") {
        // call dll func sin
    } else if (operator_ == "cos") {
        // call dll func Cos -> result
    }
        // also for Tg, ctg, Ln and other dll functions

    else {
        num2 = numbers.top();
        numbers.pop();
        if (operator_ == "+") {
            result = num1 + num2;
        } else if (operator_ == "-") {
            result = num1 - num2;
        } else if (operator_ == "*") {
            result = num1 * num2;
        } else if (operator_ == "/") {
            if (num1 == 0) {
                throw std::runtime_error("Я запрещаю делить на 0!");
            }
            result = num2 / num1;
        }
    }
    numbers.push(result);
    return result;
}