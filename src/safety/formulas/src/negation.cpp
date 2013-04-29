#include <string>
#include "safety/formulas/negation.h"

Negation::~Negation() {
}

Formula* Negation::copy() const {
    Negation* n = new Negation();
    n->child = child->copy();
    return n;
}

std::string Negation::getType() const {
    return std::string("!");
}
