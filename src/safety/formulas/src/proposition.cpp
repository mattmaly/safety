#include <istream>
#include <ostream>
#include <string>
#include "safety/formulas/proposition.h"
#include "safety/world.h"

Proposition::Proposition(const std::string& n) : Formula(), name(n) {
}

Proposition::~Proposition() {
}

void Proposition::read(std::istream& in) {
    World::registerProposition(name);
}

void Proposition::write(std::ostream& out) const {
    out << name;
}

Formula* Proposition::copy() const {
    return new Proposition(name);
}
