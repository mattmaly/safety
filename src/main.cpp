#include <iostream>
#include "safety/formula.h"
#include "safety/automaton.h"
#include "safety/translator.h"

int main(int argc, char** argv) {
    std::cout << "input formula: ";
    Formula* f = Formula::parse(std::cin);
    std::cout << "parsed & simplified formula: ";
    Formula* g = f->simplify();
    delete f;
    g->write(std::cout);
    std::cout << std::endl;

    Automaton a = Translator::translate(g);    
    delete g;
    std::cout << "resulting NFA:" << std::endl;
    a.write(std::cout);
    std::cout << std::endl;

    return 0;
}
