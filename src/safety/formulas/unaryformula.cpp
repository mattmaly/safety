#include <istream>
#include <ostream>
#include <set>
#include "safety/formulas/unaryformula.h"

UnaryFormula::UnaryFormula(Formula* c) : Formula(),
    child(c) {
}

UnaryFormula::~UnaryFormula() {
    if (child != NULL)
        delete child;
}

std::set<int> UnaryFormula::getProps() const {
    return child->getProps();
}

void UnaryFormula::read(std::istream& in) {
    child = Formula::parse(in);
}

void UnaryFormula::write(std::ostream& out) const {
    out << getType() << " " << child;
}
