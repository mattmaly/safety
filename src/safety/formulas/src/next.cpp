#include <string>
#include "safety/formulas/next.h"

Next::~Next() {
}

Formula* Next::copy() const {
    Next* n = new Next();
    n->child = child->copy();
    return n;
}

std::string Next::getType() const {
    return std::string("X");
}
