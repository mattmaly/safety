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

Formula* Conjunction::simplify() const {
    Formula* sLeft = left->simplify();
    if (sLeft->isFalse())
        return sLeft;

    Formula* sRight = right->simplify();
    if (sRight->isFalse()) {
        delete sLeft;
        return sRight;
    }
    else if (sLeft->isTrue()) {
        delete sLeft;
        return sRight;
    }
    else if (sRight->isTrue()) {
        delete sRight;
        return sLeft;
    }

    Conjunction* c = new Conjunction();
    c->left = sLeft;
    c->right = sRight;
    return c;
}

std::string Conjunction::getType() const {
    return std::string("&");
}
