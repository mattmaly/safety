#include <set>
#include <string>
#include "safety/formulas/conjunction.h"
#include "safety/formulas/disjunction.h"
#include "safety/formulas/until.h"
#include "safety/formulas/eventually.h"
#include "safety/world.h"

Until::Until(Formula* lChild, Formula* rChild) :
    Formula(),
    left(lChild),
    right(rChild) {
}

Until::~Until() {
    if (left != NULL)
        delete left;
    if (right != NULL)
        delete right;
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
    std::set<Formula*> conChildren, disChildren;
    conChildren.insert(left->evaluate(w));
    conChildren.insert(copy());
    Conjunction* c = new Conjunction(conChildren);
    disChildren.insert(right->evaluate(w));
    disChildren.insert(c);
    return new Disjunction(disChildren);
}

std::set<int> Until::getProps() const {
    std::set<int> props = left->getProps();
    std::set<int> rightProps = right->getProps();
    props.insert(rightProps.begin(), rightProps.end());
    return props;
}

std::string Until::getType() const {
    return std::string("U");
}

const Formula* Until::getLeft() const {
    return left;
}

const Formula* Until::getRight() const {
    return right;
}

void Until::read(std::istream& in) {
    left = Formula::parse(in);
    right = Formula::parse(in);
}

void Until::write(std::ostream& out) const {
    out << getType() << " " << left << " " << right;
}
