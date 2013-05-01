#include <string>
#include "safety/formulas/conjunction.h"
#include "safety/formulas/disjunction.h"
#include "safety/formulas/until.h"
#include "safety/formulas/eventually.h"
#include "safety/world.h"

Until::Until(Formula* lChild, Formula* rChild) :
    BinaryFormula(lChild, rChild) {
}

Until::~Until() {
}

Formula* Until::copy() const {
    Until* u = new Until();
    u->left = left->copy();
    u->right = right->copy();
    return u;
}

Formula* Until::simplify() const {
    Formula* sRight = right->simplify();
    if (sRight->isTrue() || sRight->isFalse())
        return sRight;    

    Formula* sLeft = left->simplify();
    if (sLeft->isFalse()) {
        delete sLeft;
        return sRight;
    }
    else if (sLeft->isTrue())
        return new Eventually(sRight);

    return new Until(sLeft, sRight);
}

Formula* Until::evaluate(const World& w) const {
    // eval(a U b, w) = eval(b,w) \/ (eval(a,w) /\ (a U b))
    Conjunction* c = new Conjunction(left->evaluate(w), copy());
    return new Disjunction(right->evaluate(w), c);
}

std::string Until::getType() const {
    return std::string("U");
}
