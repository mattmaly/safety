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

Formula* Disjunction::simplify() const {
    Formula* sLeft = left->simplify();
    if (sLeft->isTrue())
        return sLeft;

    Formula* sRight = right->simplify();
    if (sRight->isTrue()) {
        delete sLeft;
        return sRight;
    }
    else if (sLeft->isFalse()) {
        delete sLeft;
        return sRight;
    }
    else if (sRight->isFalse()) {
        delete sRight;
        return sLeft;
    }

    Disjunction* d = new Disjunction();
    d->left = sLeft;
    d->right = sRight;
    return d;
}

std::string Disjunction::getType() const {
    return std::string("|");
}
