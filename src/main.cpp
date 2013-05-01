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

    World w;
    w["p"] = true;
    w["q"] = false;
    w["r"] = true;
    Formula* eval = copy->evaluate(w);
    delete copy;
    Formula* simp = eval->simplify();
    delete eval;
    std::cout << "formula evaluated & simplified at ";
    w.write(std::cout);
    std::cout << ": ";
    simp->write(std::cout);
    std::cout << std::endl;

    delete simp;
    return 0;
}
