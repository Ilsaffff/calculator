#include <iostream>
#include "Calculator.h"

Calculator::Calculator() = default;

void Calculator::start() {
    std::string expression;

    while (true) {
        std::cout << "Введите математическое выражение: ";
        std::getline(std::cin, expression);
        double result;
        if (expression.empty()){
            break;
        }
        try {
            result = parser.parse(expression, processor);
            std::cout << "Ответ: " <<result << "\n";
        } catch (const std::exception& e){
            std::cerr << "Ошибка: " << e.what() << std::endl;
            std::cerr << "Введите заново: ";
        }
    }
}