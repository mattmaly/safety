#include <istream>
#include <ostream>
#include "safety/formulas/false.h"
#include "safety/world.h"

False::~False() {
}

void False::read(std::istream& in) {
}

void False::write(std::ostream& out) const {
    out << "false";
}

Formula* False::copy() const {
    return new False();
}

Formula* False::evaluate(const World& w) const {
    return copy();
}

bool False::isFalse() const {
    return true;
}
