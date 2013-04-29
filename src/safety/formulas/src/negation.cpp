#include <string>
#include "safety/formulas/negation.h"
#include "safety/formulas/true.h"
#include "safety/formulas/false.h"

Negation::~Negation() {
}

Formula* Negation::copy() const {
    Negation* n = new Negation();
    n->child = child->copy();
    return n;
}

Formula* Negation::simplify() const {
    Formula* sChild = child->simplify();
    if (sChild->isTrue()) {
        delete sChild;
        return new False();
    }
    else if (sChild->isFalse()) {
        delete sChild;
        return new True();
    }
    Negation* n = new Negation();
    n->child = sChild;
    return n;
}

std::string Negation::getType() const {
    return std::string("!");
}
