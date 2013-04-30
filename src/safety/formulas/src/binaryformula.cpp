#include <istream>
#include <ostream>
#include "safety/formulas/binaryformula.h"

BinaryFormula::BinaryFormula(Formula* lChild, Formula* rChild) : Formula(),
    left(lChild),
    right(rChild) {
}

BinaryFormula::~BinaryFormula() {
    if (left != NULL)
        delete left;
    if (right != NULL)
        delete right;
}

void BinaryFormula::read(std::istream& in) {
    left = Formula::parse(in);
    right = Formula::parse(in);
}

void BinaryFormula::write(std::ostream& out) const {
    out << getType() << " ";
    left->write(out);
    out << " ";
    right->write(out);
}
