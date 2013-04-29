#include <string>
#include "safety/formulas/negation.h"

Negation::~Negation() {
}

std::string Negation::getType() const {
    return std::string("!");
}
