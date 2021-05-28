#include <string>
#include "safety/formulas/negation.h"
#include "safety/formulas/true.h"
#include "safety/formulas/false.h"
#include "safety/world.h"

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

Formula* Negation::evaluate(const World& w) const {
    return new Negation(child->evaluate(w));
}

std::string Negation::getType() const {
    return std::string("!");
}
