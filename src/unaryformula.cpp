#include <istream>
#include <ostream>
#include "unaryformula.h"

UnaryFormula::~UnaryFormula() {
    if (child != NULL)
        delete child;
}

void UnaryFormula::read(std::istream& in) {
    child = Formula::parse(in);
}

void UnaryFormula::write(std::ostream& out) const {
    out << getType() << " ";
    child->write(out);
}
