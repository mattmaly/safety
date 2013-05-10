#include <iostream>
#include "safety/formula.h"
#include "safety/automaton.h"
#include "safety/translator.h"

int main(int argc, char** argv) {
    Formula* f = Formula::parse(std::cin);
    Formula* g = f->simplify();
    delete f;

    Automaton a = Translator::translate(g);    
    delete g;
    a.simplifyEdges();
    a.write(std::cout);
    std::cout << std::endl;

    return 0;
}
