#pragma once

#include "vector"
#include "SharedLibrary.h"

class LoaderLibrary {
public:
    bool openedLibrary(const std::string &nameLibrary);

    SharedLibrary &getLibrary(const std::string &nameLibrary);

    ~LoaderLibrary();

private:
    void loadLibrary(const std::string &nameLibrary);

    std::vector<SharedLibrary> openedLibraries;


};

