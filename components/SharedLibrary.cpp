#include "SharedLibrary.h"


void SharedLibrary::loadLibrary(const std::string &nameLibrary) {
    std::string filePath;
    std::stringstream ss;
    ss << "../plugins/" << "/liblib" << nameLibrary << ".so";
    filePath = ss.str();
    void *libraryHandler = dlopen(filePath.c_str(),
                                  RTLD_LAZY);

    if (!libraryHandler) {
        std::string errorMessage;
        ss << "SharedLibrary под именем " << nameLibrary << "не была загружена\n";
        errorMessage = ss.str();
        throw std::runtime_error(errorMessage.c_str());
    }
    std::cout << "Загружена SharedLibrary по имени " << nameLibrary << "\n";
    name = nameLibrary;
    handler = libraryHandler;
}

double SharedLibrary::runFunc(std::string nameFunc, const double &value) {
    nameFunc[0] = std::toupper(nameFunc[0]);
    std::string nameFuncLib;
    std::stringstream ss;
    ss << "func" << nameFunc;
    nameFuncLib = ss.str();

    double (*function)(double) = (double (*)(double)) dlsym(this->handler, nameFuncLib.c_str());
    if (!function) {
        throw std::runtime_error("Данная функция не была найдена в библиотеке!");
    }
    return function(value);
}

double SharedLibrary::runFunc(std::string name, const double &value1, const double &value2) {
    name[0] = std::toupper(name[0]);
    std::string nameFunc;
    std::stringstream ss;
    ss << "func" << name;
    nameFunc = ss.str();
    double (*function)(double, double) = (double (*)(double, double)) dlsym(this->handler,
                                                                            nameFunc.c_str());
    if (!function) {
        throw std::runtime_error("Данная функция не была найдена в библиотеке!");
    }
    return function(value1, value2);
}

void SharedLibrary::closeLib() {
    dlclose(handler);
}