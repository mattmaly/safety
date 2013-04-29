#include <string>
#include "safety/formulas/disjunction.h"

Disjunction::~Disjunction() {
}

std::string Disjunction::getType() const {
    return std::string("|");
}
