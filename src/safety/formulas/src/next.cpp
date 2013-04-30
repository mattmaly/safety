#include <string>
#include "safety/formulas/next.h"

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

std::string Next::getType() const {
    return std::string("X");
}
