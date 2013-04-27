#include <iostream>
#include "formula.h"

int main(int argc, char** argv) {
    std::cout << "input formula: ";
    Formula* f = Formula::parse(std::cin);
    std::cout << "parsed formula: ";
    f->write(std::cout);
    std::cout << std::endl;
    delete f;
    return 0;
}
