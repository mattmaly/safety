#include <istream>
#include <ostream>
#include "true.h"

True::~True() {
}

void True::read(std::istream& in) {
}

void True::write(std::ostream& out) const {
    out << "true";
}
