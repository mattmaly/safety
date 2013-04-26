#include <istream>
#include <ostream>
#include <string>
#include "proposition.h"

Proposition::Proposition(const std::string& n) : Formula(), name(n) {
}

Proposition::~Proposition() {
}

void Proposition::read(std::istream& in) {
}

void Proposition::write(std::ostream& out) const {
    out << name;
}
