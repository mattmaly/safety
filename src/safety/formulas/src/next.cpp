#include <string>
#include "safety/formulas/next.h"
#include "safety/world.h"

Next::Next(Formula* c) :
    UnaryFormula(c) {
}

Next::~Next() {
}

Formula* Next::copy() const {
    return new Next(child->copy());
}

Formula* Next::simplify() const {
    Formula* sChild = child->simplify();
    if (sChild->isTrue() || sChild->isFalse())
        return sChild;
    return new Next(sChild);
}

Formula* Next::evaluate(const World& w) const {
    // eval(X a, w) = a
    return child->copy();
}

std::string Next::getType() const {
    return std::string("X");
}
