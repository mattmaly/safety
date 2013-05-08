#include <string>
#include "safety/formulas/disjunction.h"
#include "safety/formulas/eventually.h"
#include "safety/world.h"

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

Formula* Eventually::evaluate(const World& w) const {
    // eval(F a, w) = eval(a,w) \/ (F a)
    std::set<Formula*> disChildren;
    disChildren.insert(child->evaluate(w));
    disChildren.insert(copy());
    return new Disjunction(disChildren);
}

std::string Eventually::getType() const {
    return std::string("F");
}
