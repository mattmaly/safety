#include <string>
#include "safety/formulas/negation.h"
#include "safety/formulas/true.h"
#include "safety/formulas/false.h"

Negation::Negation(Formula* c) :
    UnaryFormula(c) {
}

Negation::~Negation() {
}

Formula* Negation::copy() const {
    return new Negation(child->copy());
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
    return new Negation(sChild);
}

std::string Negation::getType() const {
    return std::string("!");
}
