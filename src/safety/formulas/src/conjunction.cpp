#include <string>
#include "safety/formulas/conjunction.h"
#include "safety/world.h"

Conjunction::Conjunction(Formula* lChild, Formula* rChild) :
    BinaryFormula(lChild, rChild) {
}

Conjunction::~Conjunction() {
}

Formula* Conjunction::copy() const {
    return new Conjunction(left->copy(), right->copy());
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

    return new Conjunction(sLeft, sRight);
}

Formula* Conjunction::evaluate(const World& w) const {
    return new Conjunction(left->evaluate(w), right->evaluate(w));
}

std::string Conjunction::getType() const {
    return std::string("&");
}
