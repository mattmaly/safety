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
    out << "(";
    typedef std::set<Formula*>::const_iterator ChildIter;
    ChildIter c = children.begin();
    (*c)->write(out);
    ++c;
    for (; c != children.end(); ++c) {
        const Formula* cf = *c;
        out << " " << getType() << " ";
        cf->write(out);
    }
    out << ")";
}

const std::set<Formula*>& CommutativeFormula::getChildren() const {
    return children;
}
