#include "LoaderLibrary.h"

bool LoaderLibrary::openedLibrary(const std::string &nameLibrary) {
    for (const SharedLibrary &lib: openedLibraries) {
        if (lib.name == nameLibrary) {
            return true;
        }
    }
    return false;
}

void LoaderLibrary::loadLibrary(const std::string &nameLibrary) {
    SharedLibrary newLibrary;
    newLibrary.loadLibrary(nameLibrary);
    this->openedLibraries.emplace_back(newLibrary);
}

SharedLibrary &LoaderLibrary::getLibrary(const std::string &nameLibrary) {
    if (!openedLibrary(nameLibrary)) {
        loadLibrary(nameLibrary);
    }
    for (SharedLibrary &lib: openedLibraries) {
        if (lib.name == nameLibrary) {
            return lib;
        }
    }
}

LoaderLibrary::~LoaderLibrary(){
    for(SharedLibrary &lib : openedLibraries){
        lib.closeLib();
    }

}
