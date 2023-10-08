#include <stack>
#include "ExpressionParser.h"
#include "string"
#include "iostream"

double ExpressionParser::parse(std::string &expression, Processor &processor) {

    std::stack<double> numbers;
    std::stack<std::string> operators;
    std::string element;
    size_t i = 0;

    while (i < expression.size()) {
        element = expression[i];
        if (expression[i] == ' ') {
            i++;
            continue;
        } else if (isdigit(expression[i])) {
            readNumber(expression, numbers, i);
        } else if (validSimpleFunctions.count(element)) {
            while (!operators.empty()) {
                if (getPriority(operators.top()) >= getPriority(element)) {
                    processor.process(numbers, operators);
                } else {
                    break;
                }
            }
            operators.emplace(element);
            i++;
        } else if (element == "(") {
            operators.emplace(element);
            i++;
        } else if (element == ")") {
            while (!operators.empty()) {
                if (operators.top() != "(") {
                    processor.process(numbers, operators);
                } else {
                    break;
                }
            }
            if (operators.empty()) {
                break;
            }
            operators.pop();
            i++;
        } else if (!isdigit(expression[i])) {
            readFunction(expression, operators, i);
        } else {
            throw std::runtime_error("Вы ввели невалидное выражение");
        }

    }
    while (!operators.empty()) {
        processor.process(numbers, operators);
    }
    return numbers.top();
}

void ExpressionParser::readNumber(std::string &expression, std::stack<double> &numbers, size_t &i) {
    std::string num;
    while (i < expression.size() && isdigit(expression[i]) && expression[i] != ' ') {
        num += expression[i];
        i++;
    }
    numbers.push(std::stod(num));
}

void ExpressionParser::readFunction(std::string &expression, std::stack<std::string> &operators,
                                    size_t &i) {
    std::string func;
    while (i < expression.size() && isalpha(expression[i]) && expression[i] != ' ') {
        func += expression[i];
        i++;
    }
    if (validFunctions.count(func) != 0) {
        operators.push(func);
    } else {
        throw std::runtime_error("Вы ввели некорректную функцию");
    }
    if (expression[i] == '(') {
        i++;
    }
}

int ExpressionParser::getPriority(std::string &operator_) {
    if (operator_ == "+" || operator_ == "-") return 1;
    else if (operator_ == "*" || operator_ == "/") return 2;
    else if (operator_ == "^") return 3;
    return 0;
}