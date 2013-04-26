#include <string>
#include "disjunction.h"

Disjunction::~Disjunction() {
}

std::string Disjunction::getType() const {
    return std::string("|");
}
