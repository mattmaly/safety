#include <iostream>
#include "safety/formula.h"

int main(int argc, char** argv) {
    std::cout << "input formula: ";
    Formula* f = Formula::parse(std::cin);
    std::cout << "parsed formula: ";
    f->write(std::cout);
    std::cout << std::endl;

    Formula* copy = f->copy();
    delete f;
    std::cout << "copy of parsed formula: ";
    copy->write(std::cout);
    std::cout << std::endl;
    delete copy;

    return 0;
}
