#include <algorithm>
#include <ostream>
#include <sstream>
#include <set>
#include <string>
#include "safety/formulas/commutativeformula.h"

CommutativeFormula::CommutativeFormula(const std::set<Formula*>& c) :
    Formula(),
    children(c) {
}

CommutativeFormula::~CommutativeFormula() {
    typedef std::set<Formula*>::iterator ChildIter;
    for (ChildIter c = children.begin(); c != children.end(); ++c)
        delete *c;
}

std::set<int> CommutativeFormula::getProps() const {
    std::set<int> props;
    typedef std::set<Formula*>::const_iterator ChildIter;
    for (ChildIter c = children.begin(); c != children.end(); ++c) {
        std::set<int> childProps = (*c)->getProps();
        props.insert(childProps.begin(), childProps.end());
    }
    return props;
}

void CommutativeFormula::read(std::istream& in) {
    /* for the sake of easily-parse-able input,
       we are currently assuming that the user inputs commutative formulas
       in a binary style */
    Formula* left = Formula::parse(in);
    Formula* right = Formula::parse(in);
    children.insert(left);
    if (children.find(right) == children.end())
        children.insert(right);
    else
        delete right;
}

void CommutativeFormula::write(std::ostream& out) const {
    typedef std::set<Formula*>::const_iterator ChildIter;
    ChildIter c = children.begin();
    out << "(" << *c;
    ++c;
    for (; c != children.end(); ++c)
        out << " " << getType() << " " << *c;
    out << ")";
}

const std::set<Formula*>& CommutativeFormula::getChildren() const {
    return children;
}
