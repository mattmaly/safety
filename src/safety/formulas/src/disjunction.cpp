#include <string>
#include "safety/formulas/disjunction.h"

Disjunction::Disjunction(Formula* lChild, Formula* rChild) :
    BinaryFormula(lChild, rChild) {
}

Disjunction::~Disjunction() {
}

Formula* Disjunction::copy() const {
    return new Disjunction(left->copy(), right->copy());
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

    return new Disjunction(sLeft, sRight);
}

std::string Disjunction::getType() const {
    return std::string("|");
}
