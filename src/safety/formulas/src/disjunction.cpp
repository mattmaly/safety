#include <string>
#include "safety/formulas/disjunction.h"
#include "safety/world.h"

Disjunction::Disjunction(Formula* lChild, Formula* rChild) :
    CommutativeFormula(lChild, rChild) {
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

Formula* Disjunction::evaluate(const World& w) const {
    return new Disjunction(left->evaluate(w), right->evaluate(w));
}

std::string Disjunction::getType() const {
    return std::string("|");
}
