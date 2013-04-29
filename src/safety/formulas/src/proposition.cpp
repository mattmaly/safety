#include <istream>
#include <ostream>
#include <string>
#include "safety/formulas/proposition.h"

Proposition::Proposition(const std::string& n) : Formula(), name(n) {
}

Proposition::~Proposition() {
}

void Proposition::read(std::istream& in) {
}

void Proposition::write(std::ostream& out) const {
    out << name;
}
