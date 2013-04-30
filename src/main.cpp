#include <iostream>
#include "safety/formula.h"

int main(int argc, char** argv) {
    std::cout << "input formula: ";
    Formula* f = Formula::parse(std::cin);
    std::cout << "parsed formula: ";
    f->write(std::cout);
    std::cout << std::endl;

    Formula* copy = f->simplify();
    delete f;
    std::cout << "simplified parsed formula: ";
    copy->write(std::cout);
    std::cout << std::endl;
    delete copy;

    return 0;
}
