#include <string>
#include "safety/formulas/conjunction.h"

Conjunction::~Conjunction() {
}

Formula* Conjunction::copy() const {
    Conjunction* c = new Conjunction();
    c->left = left->copy();
    c->right = right->copy();
    return c;
}

std::string Conjunction::getType() const {
    return std::string("&");
}
