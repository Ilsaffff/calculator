#include <iostream>
#include "Calculator.h"

Calculator::Calculator() = default;

void Calculator::start() {
    std::string expression;
    std::cout << "Введите математическое выражение: ";
    while (getline(std::cin, expression)) {
        double result;
        try {
            result = parser.parse(expression, processor);
            std::cout << "Ответ: " <<result << "\n";
            std::cout << "Введите математическое выражение: ";
        } catch (const std::exception& e){
            std::cerr << "Ошибка: " << e.what() << std::endl;
            std::cerr << "Введите заново: ";
        }
    }
}