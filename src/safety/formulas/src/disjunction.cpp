#include <string>
#include "safety/formulas/disjunction.h"

Disjunction::~Disjunction() {
}

Formula* Disjunction::copy() const {
    Disjunction* d = new Disjunction();
    d->left = left->copy();
    d->right = right->copy();
    return d;
}

std::string Disjunction::getType() const {
    return std::string("|");
}
