#include <string>
#include "conjunction.h"

Conjunction::~Conjunction() {
}

std::string Conjunction::getType() const {
    return std::string("&");
}
