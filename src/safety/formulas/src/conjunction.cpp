#include <string>
#include "safety/formulas/conjunction.h"

Conjunction::~Conjunction() {
}

std::string Conjunction::getType() const {
    return std::string("&");
}
