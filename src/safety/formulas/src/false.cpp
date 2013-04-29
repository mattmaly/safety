#include <istream>
#include <ostream>
#include "safety/formulas/false.h"

False::~False() {
}

void False::read(std::istream& in) {
}

void False::write(std::ostream& out) const {
    out << "false";
}
