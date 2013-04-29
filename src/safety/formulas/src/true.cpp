#include <istream>
#include <ostream>
#include "safety/formulas/true.h"

True::~True() {
}

void True::read(std::istream& in) {
}

void True::write(std::ostream& out) const {
    out << "true";
}

Formula* True::copy() const {
    return new True();
}

bool True::isTrue() const {
    return true;
}
