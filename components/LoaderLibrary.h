#ifndef CALCULATOR_LOADERLIBRARY_H
#define CALCULATOR_LOADERLIBRARY_H

#include "vector"
#include "SharedLibrary.h"

class LoaderLibrary {
public:
    bool openedLibrary(const std::string &nameLibrary);

    SharedLibrary getLibrary(const std::string &nameLibrary);

private:
    void loadLibrary(const std::string &nameLibrary);

    std::vector<SharedLibrary> openedLibraries;
};

#endif //CALCULATOR_LOADERLIBRARY_H
