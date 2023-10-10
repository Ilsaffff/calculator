cmake_minimum_required(VERSION 3.26)
project(calculator)

set(CMAKE_CXX_STANDARD 17)



add_executable(calculator main.cpp
        components/ExpressionParser.cpp
        components/ExpressionParser.h
        components/Calculator.cpp
        components/Calculator.h
        components/Processor.cpp
        components/Processor.h
        components/LoaderLibrary.cpp
        components/LoaderLibrary.h
        components/SharedLibrary.cpp
        components/SharedLibrary.h
)