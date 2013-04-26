#include <string>
#include "negation.h"

Negation::~Negation() {
}

std::string Negation::getType() const {
    return std::string("!");
}
