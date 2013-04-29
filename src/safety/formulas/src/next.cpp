#include <string>
#include "safety/formulas/next.h"

Next::~Next() {
}

std::string Next::getType() const {
    return std::string("X");
}
