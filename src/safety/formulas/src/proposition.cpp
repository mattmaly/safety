#include <istream>
#include <ostream>
#include <set>
#include <string>
#include "safety/formulas/true.h"
#include "safety/formulas/false.h"
#include "safety/formulas/proposition.h"
#include "safety/world.h"

Proposition::Proposition(const std::string& n) : Formula(), name(n) {
}

Proposition::~Proposition() {
}

std::set<int> Proposition::getProps() const {
    std::set<int> p;
    p.insert(World::registerProposition(name));
    return p;
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

Formula* Proposition::evaluate(const World& w) const {
    if (!w.contains(name))
        return copy();
    if (w[name])
        return new True();
    return new False();
}
