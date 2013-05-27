#include <istream>
#include <ostream>
#include <set>
#include "safety/formulas/true.h"
#include "safety/world.h"

True::~True() {
}

std::set<int> True::getProps() const {
    return std::set<int>();
}

void True::read(std::istream& in) {
}

void True::write(std::ostream& out) const {
    out << "true";
}

Formula* True::copy() const {
    return new True();
}

Formula* True::evaluate(const World& w) const {
    return copy();
}

bool True::isTrue() const {
    return true;
}
