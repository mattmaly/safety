#include <string>
#include "safety/formulas/eventually.h"

Eventually::Eventually(Formula* c) :
    UnaryFormula(c) {
}

Eventually::~Eventually() {
}

Formula* Eventually::copy() const {
    return new Eventually(child->copy());
}

Formula* Eventually::simplify() const {
    Formula* sChild = child->simplify();
    if (sChild->isTrue() || sChild->isFalse())
        return sChild;
    return new Eventually(sChild);
}

std::string Eventually::getType() const {
    return std::string("F");
}
